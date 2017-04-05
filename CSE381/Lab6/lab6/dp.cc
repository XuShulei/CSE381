#include<stdio.h>
#include"Chopstick.h"
#include"thread.h"


#define MAX 7

Chopstick Chopsticks[MAX];

void dinning(int id) {
	Chopsticks[id].get();
	Chopsticks[(id+1)%MAX].get();
	printf("Philosopher %d pciks up the chopstick %d and %d.\n", id, id, (id+1)%MAX);
	Chopsticks[id].put();
	Chopsticks[(id+1)%MAX].put();
	printf("Philosopher %d puts down the chopstick %d and %d.\n", id, id, (id+1)%MAX);
	thread_exit(id);
}


thread_t threads[MAX];

int  main( )  {
	int i;
	for( i = 0; i < MAX; i++){
	  	thread_create(&threads[i],dinning,i);
	}


	for( i = 0; i < MAX; i++){
	  	thread_join(threads[i]);
	}

	return 0;
}   
