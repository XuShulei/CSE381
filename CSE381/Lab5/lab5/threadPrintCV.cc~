#include<stdio.h>
#include<stdlib.h>
#include "thread.h"


void print_thread( int id ){
int  max;
int  i;

   printf("TH-%d The thread %d is going to print\n",id,id);
   max = rand( )%10;
   max = max< 3  ? 3: max;
   for( i = 0; i< max; i++){
     printf("TH-%d  prints message %d\n",id,i);
  }  
  printf("TH-%d The thread %d is DONE!\n",id,id);
  thread_exit( i );

} 

#define MAX 24
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
