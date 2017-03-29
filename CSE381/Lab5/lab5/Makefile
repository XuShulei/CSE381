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


threadPrint: threadPrint.o  $(THREADLIBS)
	g++ $(MYLIB) $^ -o $@


threadPrintCV: threadPrintCV.o  $(THREADLIBS)
	g++ $(MYLIB) $^ -o $@


threadPrintPL: threadPrintPL.o  PriorityLock.o $(THREADLIBS)
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

