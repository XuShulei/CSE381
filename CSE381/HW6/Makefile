BINARIES :=  threadHello TSQueueMain BBQMain RWLockMain BarberShopMain
all: $(BINARIES)

CFLAGS := $(CFLAGS) -g -Wall -Werror -D_POSIX_THREAD_SEMANTICS

THREADLIBS := Lock.o CV.o thread.o
CTHREADLIBS := thread.o
MYLIB  := -pthread

clean:
	rm -f *.o $(BINARIES)

tags:
	etags *.h *.c *.cc

%.o: %.cc
	g++ -c $(CFLAGS) $< -o $@

%.o: %.c
	gcc -c $(CFLAGS) $< -o $@

threadHello: threadHello.o  $(CTHREADLIBS)
	gcc $(MYLIB) $^ -o $@


dp: dp.o Chopstick.o  $(THREADLIBS)
	g++ $(MYLIB) $^ -o $@

Exe12: Exe12.o Kitchen.o  $(THREADLIBS)
	g++ $(MYLIB) $^ -o $@

Exe13: Exe13.o Kitchen.o  $(THREADLIBS)
	g++ $(MYLIB) $^ -o $@

threadPrintPCV: threadPrintPCV.o PCV.o  $(THREADLIBS)
	g++ $(MYLIB) $^ -o $@

threadPrintPCV_signal: threadPrintPCV_signal.o PCV.o  $(THREADLIBS)
	g++ $(MYLIB) $^ -o $@

threadPrintPCV_broadcast: threadPrintPCV_broadcast.o PCV.o  $(THREADLIBS)
	g++ $(MYLIB) $^ -o $@

TSQueueMain: TSQueueMain.o TSQueue.o $(THREADLIBS)
	g++ $(MYLIB) $^ -o $@

RWLockMain: RWLockMain.o RWLock.o RWObj.o $(THREADLIBS)
	g++ $(MYLIB) $^ -o $@

BBQMain: BBQMain.o BBQ.o $(THREADLIBS)
	g++ $(MYLIB) $^ -o $@

BarberShopMain: BarberShopMain.o BarberShop.o $(THREADLIBS)
	g++ $(MYLIB) $^ -o $@

CounterMain: CounterMain.o Counter.o $(THREADLIBS)
	g++ $(MYLIB) $^ -o $@

