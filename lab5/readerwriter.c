#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t mutex;
sem_t rw_mutex;
int readcount =0;
/*all needed functions:*/
void *reader(void *param){
  printf("\nReader is entering...");
  sem_wait(&mutex);
  readcount++;
  if(readcount==1)
  sem_wait(&rw_mutex);
  printf("\n%d Reader is inside",readcount);
  sem_post(&mutex);
  sleep(rand() % 3 + 1); // Sleeps randomly between 1 and 3 seconds
  sem_wait(&mutex);
  readcount--;
  if(readcount==0)
  sem_post(&rw_mutex);
  sem_post(&mutex);
  printf("\nReader is leaving");
}
void *writer(void *param){
  printf("\nWriter is entering...");
  sem_wait(&rw_mutex);
  printf("\nWriter is inside");
  sleep(rand() % 3 + 1); // Sleeps randomly between 1 and 3 seconds
  sem_post(&rw_mutex);
  printf("\nWriter is leaving");
 }

int main(){
  sem_init(&mutex,0,1);
  sem_init(&rw_mutex,0,1);//initializing
  int r,w,i;
  printf("\nHow many readers we have?");
  scanf("%d",r);
  printf("\nHow many writers we have?");
  scanf("%d",w);
  /*We create thread pid for both readers and writers*/
  pthread_t pid;
  for(i=0;i<r;i++)
  pthread_create(&pid, NULL, reader, NULL);
  for(i=0;i<w;i++)
  pthread_create(&pid, NULL, writer, NULL);
  sleep(20);//overall how long program exectutes, sleeping untill termination
  return 0;
}

