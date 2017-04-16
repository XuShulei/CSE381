#include<stdio.h>
#include<stdlib.h>
#include "thread.h"
#include "Lock.h"
#include "PCV.h"

Lock lock;
#define MAX 10
int numOfRunning = 0;
CV cv;
PCV pcv;

void print_thread( int id ){
int  i;

 lock.acquire();
 numOfRunning++;
   printf("TH-%d The thread %d is going to print\n",id,id);
	if (numOfRunning == MAX) {
		pcv.broadcast(&lock, 0);

	} else {
	// wait until all threads activated	
	while (numOfRunning < MAX) {
		pcv.wait(&lock, id);
	}
	}
	//pcv.wait(&lock, id);

   for( i = 0; i< 3; i++){
     printf("TH-%d  prints message %d\n",id,i);
  }  
  printf("TH-%d The thread %d is DONE!\n",id,id);

//  pcv.signal(&lock);

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
