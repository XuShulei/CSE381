#include "PCV.h"

PCV::PCV() { state = 0; }

PCV::~PCV() {}
	
void PCV::wait(Lock *enclosingLock, int priority){
	lock.acquire();
	CV *myCV = new CV;
	waiting.push(std::make_pair(priority, myCV));
	lock.release();
//	printf("push %d\n", priority);
	myCV->wait(enclosingLock);
}
	
void PCV::signal(Lock *enclosingLock) {
	lock.acquire();
	if (waiting.empty()) {
		state = 0;
	} else {
		CV* top = waiting.top().second;
		top->signal();
//		printf("Signal %d\n", waiting.top().first);
		waiting.pop();
		delete top;
	}
	lock.release();
}
	
void PCV::broadcast(Lock *enclosingLock, int priority) {
	while (!waiting.empty() && waiting.top().first >= priority)
		PCV::signal(enclosingLock);
}
