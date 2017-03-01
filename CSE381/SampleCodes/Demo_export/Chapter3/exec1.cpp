#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

main() {
  char command[100];
  char *argv[10];
  strcpy(command, "/bin/ls");
  argv[0] = command;
  strcpy(argv[1], "/");
  argv[2] = NULL;
  execv(command, argv);
  std::cout << "finished\n";
}
