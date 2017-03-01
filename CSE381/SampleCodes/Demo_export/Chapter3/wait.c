#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main( ){

int pid  ;
int val = 5;
int status = 0;


if( pid = fork( ) )
  wait( &status );

 val++;

 printf("status is %d, Val is %d\n", status, val);

 if( pid ){
   if( WIFEXITED(status) ){ 
      printf("WIFEXITED(status)\n");
   } else if(  WEXITSTATUS(status) ){
     printf(" WEXITSTATUS(status)\n" );
  } else 
    printf("else\n");

 }

 return val;

}
