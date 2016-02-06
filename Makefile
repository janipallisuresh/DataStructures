SRCHOME=./src
CC=gcc
CFLAGS=-Wall -g -I$(SRCHOME)
SLL_TARGET=singlelinkedlist
DLL_TARGET=doublelinkedlist
Q_TARGET=queue
S_TARGET=stack
SHARED_SLL_TARGET=libsll
SHARED_DLL_TARGET=libdll
SHARED_Q_TARGET=libmyqueue
SHARED_S_TARGET=libmystack

SLL_SRC := $(SRCHOME)/singlelinkedlist.c $(SRCHOME)/singlelinkedlist.h 
DLL_SRC := $(SRCHOME)/doublelinkedlist.c $(SRCHOME)/doublelinkedlist.h 
Q_SRC := $(SRCHOME)/queue.c $(SRCHOME)/queue.h
S_SRC := $(SRCHOME)/stack.c $(SRCHOME)/stack.h

shared_sll: $(SHARED_SLL_TARGET)

shared_dll: $(SHARED_DLL_TARGET)

shared_myqueue: $(SHARED_Q_TARGET)

shared_mystack: $(SHARED_S_TARGET)

sll: $(SLL_TARGET)

dll: $(DLL_TARGET)

myqueue: $(Q_TARGET)

mystack: $(S_TARGET)

all: $(SLL_TARGET) $(DLL_TARGET) $(Q_TARGET) $(S_TARGET)

shared_all: $(SHARED_SLL_TARGET) $(SHARED_DLL_TARGET) $(SHARED_Q_TARGET) $(SHARED_S_TARGET)

$(SLL_TARGET): $(SLL_SRC) $(SRCHOME)/s_main.c
	$(CC) $(CFLAGS) $(SLL_SRC) $(SRCHOME)/s_main.c -o $(SLL_TARGET)


$(DLL_TARGET): $(DLL_SRC) $(SRCHOME)/d_main.c
	$(CC) $(CFLAGS) $(DLL_SRC) $(SRCHOME)/d_main.c -o $(DLL_TARGET)

$(Q_TARGET): $(Q_SRC) $(DLL_SRC) $(SRCHOME)/queue_main.c
	$(CC) $(CFLAGS) $(Q_SRC) $(DLL_SRC) $(SRCHOME)/queue_main.c -o $(Q_TARGET)

$(S_TARGET): $(S_SRC) $(SLL_SRC) $(SRCHOME)/stack_main.c
	$(CC) $(CFLAGS) $(S_SRC) $(SLL_SRC) $(SRCHOME)/stack_main.c -o $(S_TARGET)

$(SHARED_SLL_TARGET): $(SLL_SRC)
	$(CC) -shared -o $(SHARED_SLL_TARGET).so -fPIC $(SLL_SRC)

$(SHARED_DLL_TARGET): $(DLL_SRC)
	$(CC) -shared -o $(SHARED_DLL_TARGET).so -fPIC $(DLL_SRC)

$(SHARED_Q_TARGET): $(Q_SRC) $(DLL_SRC)
	$(CC) -shared -o $(SHARED_Q_TARGET).so -fPIC $(Q_SRC) $(DLL_SRC)

$(SHARED_S_TARGET): $(Q_SRC) $(SLL_SRC)
	$(CC) -shared -o $(SHARED_S_TARGET).so -fPIC $(S_SRC) $(SLL_SRC)

clean:
	rm -rf *.o *~ $(SLL_TARGET) $(DLL_TARGET) $(Q_TARGET) $(S_TARGET) $(SHARED_SLL_TARGET).so $(SHARED_DLL_TARGET).so $(SHARED_Q_TARGET).so $(SHARED_S_TARGET).so 
