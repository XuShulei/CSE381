#include <unistd.h>
#include <stdio.h>
#include<sys/wait.h>

int  main( ){

   int child_pid = fork();
   int tmp = 0;

    
    if (child_pid == 0) {           // I'm the child process
        printf("I am process #%d, the child process waits for input\n", getpid());
        scanf(" %d\n",&tmp);
        printf("The child input is %d",tmp);
    } else {                        // I'm the parent process
        printf("I am parent of process #%d and waits for input  \n", child_pid);
        scanf("%d\n",&tmp);
        printf("The parent  input is %d",tmp);
    }   
   
    
    wait( NULL ); // wait for the child process terminate
    return 0;
}

