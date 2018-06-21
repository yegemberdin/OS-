#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t chopstick[5];
/*all needed functions:*/
void *philosopher(int n){
  printf("\nPhilosopher %d is thinking for awhile...",n);
  sem_wait(&chopstick[n]);
  sem_wait(&chopstick[(n+1)%5]);
  printf("\nPhilosopher %d is eating for awhile...",n);
  sleep(5);
  sem_post(&chopstick[n]);
  sem_post(&chopstick[(n+1)%5]);
  printf("\nPhilosopher %d finished eating",n);
}
int main(){
  pthread_t philosopher[5];
  int i,k;
  void *msg;
  for(i=0;i<=5;i++){
  k=sem_init(&chopstick[i],0,1);//initializing
  if(k==-1){printf("\nError semaphore initialization"); exit(1);}
  }
  for(i=0;i<=5;i++){
  k=pthread_create(&philosopher[i], NULL, (void*) philosopher, (int *)i);
  if(k!=0){
    printf("\nError thread creation \n");exit(1);}
  }
  for(i=0;i<=5;i++){
  k=pthread_join(&philosopher[i],&msg);
  if(k!=0){
    printf("\nError thread join \n");exit(1);}
  }
  for(i=0;i<=5;i++){
  k=sem_destroy(&chopstick[i]);
  if(k!=0){
    printf("\nSemaphore destoroyed \n");exit(1);}
  }
  return 0;
}


