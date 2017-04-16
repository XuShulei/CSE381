#include<stdio.h>
#include<stdlib.h>
#include "thread.h"
#include "Lock.h"
#include "PCV.h"

#define MAX 24

Lock lock;
PCV pcv;
CV  cvWaitBroadcast;
int totalRunning = 0;
int  done = 0;

void print_thread( int id ){
int  max;
int  i;
   

   
   lock.acquire( );
   
   
   pcv.wait( &lock, id );
   
   
   printf("TH-%d The thread %d is going to print\n",id,id);
   max = rand( )%10;
   max = max< 3  ? 3: max;
   
   for( i = 0; i< max; i++){
     printf("TH-%d  prints message %d\n",id,i);
   }  
   done++;
  printf("TH-%d The thread %d is DONE, done is %d\n",id,id,done);
  
  
  if( done ==  4 ){
     cvWaitBroadcast.signal( );
     printf("*****************************\nTH-%d cvWaitBroadcast.signal( ) is issued\n",id);
  }
     
        
  lock.release( );
  thread_exit( i );
  
} 

thread_t  threads[MAX];

int  main( ){

  int i;

  for( i = 0; i < MAX; i++){
  	thread_create(&threads[i],print_thread,i);
  }
  printf("%d threads are created\n",MAX);


  
  
  printf("\nMain pcv.singal( ) \n");
  pcv.signal( &lock);
  
   
  printf("\nMain pcv.singal( ) \n");
  pcv.signal( &lock);
  
  printf("\nMain pcv.singal( ) \n");
  pcv.signal( &lock);
  
  
   
   printf("\nMain pcv.broadcast( ) priority %d\n", MAX/2);
   pcv.broadcast( &lock, MAX/2);
   

  

   lock.acquire( );
   printf("Main thread is waiting for cvWaitBroadcast\n");
   cvWaitBroadcast.wait( &lock );
   lock.release( );
   printf("\nMain pcv.broadcast( ) priority %d\n", 0 );
   pcv.broadcast( &lock, 0 );
   



  for( i = 0; i < MAX; i++){
  	thread_join(threads[i]);
  }

 printf("Main thread is done!\n");

}
