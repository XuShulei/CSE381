#include <stdio.h>
#include "Lock.h"
#include "thread.h"
#include "CV.h"

class Chopstick {

public:
	Chopstick();
	~Chopstick();
	void get();
	void put();

private:
	int used;
	Lock lock;
	CV cv;
};
