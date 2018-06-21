#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define BUFFER_SIZE 5
typedef int buffer_item;
buffer_item buffer[BUFFER_SIZE];
pthread_mutex_t mutex;
sem_t full, empty;/*our empty and full semaphores,which represent data structure
                   The semaphore empty is initialized to the number of buffers,
                   the semaphore full is initialized to the value 0.*/
int count =0;
int in =0;
int out = 0;
/*all needed functions:*/
int insert_item(buffer_item item){/*function which adds some randomly taken item to buffer, created for producer*/
  int success;
  sem_wait(&empty);
  pthread_mutex_lock(&mutex);
  if( count != BUFFER_SIZE){
    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    count++;
    success = 0;
  }
  else
    success = -1;

  pthread_mutex_unlock(&mutex);
  sem_post(&full);

  return success;
}
int remove_item(buffer_item *item){/*function which deletes object from buffer and replace it in item, created for consumer*/
  int success;
  sem_wait(&full);
  pthread_mutex_lock(&mutex);
  if( count != 0){
    *item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    count--;
    success = 0;
  }
  else
    success = -1;

  pthread_mutex_unlock(&mutex);
  sem_post(&empty);

  return success;
}
void *producerf(void *param){
  buffer_item item;
  while(1){
    sleep(rand() % 3 + 1); // Sleeps randomly between 1 and 3 seconds
    item = rand();
    if(insert_item(item))
      printf("Error!\n");
    else
      printf("Producer produced %d\n", item);
  }
}
void *consumerf(void *param){
  buffer_item item;
  while(1){
    sleep(rand() % 3 + 1);
    if(remove_item(&item))
      printf("Error!\n");
    else
      printf("Consumer consumed %d\n", item);
  }
}

int main(int argc, char *argv[]){
  pthread_mutex_init(&mutex, NULL);
  sem_init(&empty, 0, BUFFER_SIZE);
  sem_init(&full, 0, 0);
  /*above code initialize that all of buffer is empty in the begining*/

  /*We create each producer and consumer thread, making assumption that there is only one producer and one consumer*/
  pthread_t producer;
  pthread_t consumer;
  pthread_create(&producer, NULL, producerf, NULL);
  pthread_create(&consumer, NULL, consumerf, NULL);
  sleep(20);//overall how long program exectutes, sleeping untill termination
  return 0;
}

