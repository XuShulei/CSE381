#include <unistd.h>
#include <stdio.h>
#include <string.h>

void main()
{
    char *s, buf[1024];
     int fds[2];
     s = "hello world\n";
     pipe(fds);
     write(fds[1], s, strlen(s));
     read(fds[0], buf, strlen(s));
     printf("fds[0] = %d, fds[1] = %d\n", fds[0], fds[1]);
     write(1, buf, strlen(s));
}

