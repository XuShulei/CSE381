#include <queue>
#include <stdio.h>
#include <utility>
#include "Lock.h"
#include "CV.h"

class PCV {

public:
	PCV();
	~PCV();
	void wait(Lock *enclosingLock, int priority);
	void signal(Lock *enclosingLock);
	void broadcast(Lock *enclosingLock, int priority);

private:
	std::priority_queue<std::pair<int, CV*> > waiting;
	CV cv;
	Lock lock;
	int state;
};
