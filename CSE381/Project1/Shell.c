#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/wait.h>

#define MAX_LINE 80 // The maximum length command
#define MAX_HISTORY 10 // The maximum history listed
#define MAX_BUFFER 100 // The maximum buffer of history command

char history[MAX_HISTORY][MAX_BUFFER];
int count = 0;

/**
 * This method is used by updateHistory() method to display user's history command
*/
void displayHistoryCommand() {
	int hist = count;
	int j = 0;
	
	for (int i=0; i<MAX_HISTORY; i++) {
		printf("%d. ", hist);
		while (history[i][j] != '\n' && history[i][j] != '\0') {
			printf("%c", history[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		hist--;
		if (hist == 0)	break;
	}
}

/* This method is used by processCommand() method to update the history buffer.*/
int updateHistory(char input[], char *args[]) {
	if (strcmp(args[0], "history") == 0) {//when input "history"
		if (count > 0)	displayHistoryCommand();
		else	printf("No command in history!\n");
		return -1;
	} 
	else if (args[0][0] == '!') { // when 1st ! appears
		if (args[0][1] == '!') {// when 2nd char is !
			strcpy(input, history[0]);
		}
		else if (args[0][1] == '0') { // when input !0
			printf("No such command in history!\n");
			return -1;
		}
		else { // when input !N
			int i = 0;
			int numInt = 0;
			char num[10];
			int hist = 0;
			while (args[0][i+1] < '9' && args[0][i+1] > '0') { //first get the N as char[]
				num[i] = args[0][i+1];
				i++;
			}
			while (i > 0) {	// then get N as int
				i--;
				numInt = numInt * 10 + (num[i] - '0');
			}
			hist = count - numInt;
			if (hist < 0 || hist > 9) {
				printf("No such command in history!\n");
				return -1;
			}
			else {
				strcpy(input, history[hist]);
			}
		}
	}
	else { // when not input history, we need to update history buffer
		for (int i = MAX_HISTORY-1; i > 0; i--) {
			strcpy(history[i], history[i-1]);
		}
		strcpy(history[0], input);
		count++;
	}
	return 0;
}

/* This method is used to process input command string.
 * return 0 if this command is valid, return -1 if this commmand is invalid
 */
int processCommand(char input[], char *args[], int *flag) {
	
	int length;
	int begin = -1;
	int index = 0;

	length = strlen(input);
	if (length == 0)	exit(0);
	else if(length < 0) { // terminate if no command read
		printf("Error! Command not read!");
		exit(-1);
	}
	
	// use this for loop to process the input command
	for (int i=0; i < length; i++) {
		switch(input[i]) {
			case '\n':
				if (begin != -1) {
					args[index] = &input[begin];
					index++;
				}
				args[index] = NULL;
				input[i] = '\0';
				break;
			case ' ':case '\t': // to next argument
				if (begin != -1) {
					args[index] = &input[begin];
					index++;
				}
				input[i] = '\0';
				begin = -1;
				break;
			default:
				if (begin == -1)	begin = i;
				if (input[i] == '&') {	// if meet '&', set flag to 1
					*flag = 1;
					input[i] = '\0';
				}
				break;
		}
	}

	args[index] = NULL; // set null when input line > 80
	
	
	return updateHistory(input, args);

}


int main() {

	int cflag; // flag used to check '&'	
	char *args[MAX_LINE/2 + 1]; // command line argument
	char input[MAX_LINE];
	int shouldRun = 1;
	pid_t pid;
	

	while (shouldRun) {
		printf("osh>");
		fflush(stdout);
		cflag = 0;
		args[0] = "";
		fgets(input, MAX_LINE, stdin);
		
		if (processCommand(input, args, &cflag) != -1) { // when not input history
			pid = fork();
			if (strcmp(args[0], "exit") == 0)	shouldRun = 0;
			else if (pid == 0) { // if it is the child process
				int result = execvp(args[0], args);
				if (result == -1)	printf("Error! Fail to execute command!\n");
			}
			else if (pid > 0) { // if it is the parent process
				if (cflag == 0) {// when there is no '&', need to wait
					wait(NULL);
				}
			} 
			else { // when fail to fork
				printf("Error! Fail to fork!\n");
				exit(1);
			}
		}
	}

	return 0;
}
