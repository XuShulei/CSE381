#include<stdio.h>
#include<stdlib.h>
#include "thread.h"
#include "Lock.h"
#include "CV.h"

Lock lock;
#define MAX 24
int numOfRunning = 0;
CV printGo;

void print_thread( int id ){
int  max;
int  i;

 lock.acquire();
 numOfRunning++;
 	while (numOfRunning < MAX) {
		printGo.wait(&lock);
	}
   printf("TH-%d The thread %d is going to print\n",id,id);
   max = rand( )%10;
   max = max< 3  ? 3: max;
   for( i = 0; i< max; i++){
     printf("TH-%d  prints message %d\n",id,i);
  }  
  printf("TH-%d The thread %d is DONE!\n",id,id);

  lock.release();
  thread_exit( i );
} 

thread_t  threads[MAX];

int  main( ){

  int i;

  for( i = 0; i < MAX; i++){
  	thread_create(&threads[i],print_thread,i);
  }


  for( i = 0; i < MAX; i++){
  	thread_join(threads[i]);
  }

 printf("Main thread is done!\n");

}
