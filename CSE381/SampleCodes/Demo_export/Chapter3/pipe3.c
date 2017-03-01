#include<stdio.h>
#include <unistd.h>
#include <stdio.h>


void main()
{
    char *s, buf[1024];      //                                    11111   33333   11111  33333
     int fds[2];             //                                       22222   44444   33333  11111
     s = "hello world\n";    //                                33333   11111   22222  22222
     pipe(fds);              //                                      44444    22222   44444  44444
     if (fork() == 0) {
         printf("11111 \n");     /* how to make 111111 before 444444 */
         read(fds[0], s, 6);
         printf("22222\n");
     } else {
       printf("33333\n");
       write(fds[1], buf, 6);
       printf("44444\n");
    }
}
