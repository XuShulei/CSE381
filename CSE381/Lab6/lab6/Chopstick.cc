#include "Chopstick.h"

Chopstick::Chopstick() { used = 0; }

Chopstick::~Chopstick() {}

void
Chopstick::get() {
	lock.acquire();
	while (used != 0) {
		cv.wait(&lock);
	}
	used = 1;
	lock.release();
	return;
}

void
Chopstick::put() {
	lock.acquire();
	if (used == 1) {
		used = 0;
		cv.signal();
	}
	lock.release();
	return;
}