CC=gcc
CFLAGS=-Wall -g
SLL_TARGET=singlelinkedlist
DLL_TARGET=doublelinkedlist
SHARED_SLL_TARGET=libsll
SHARED_DLL_TARGET=libdll

sll_shared: $(SHARED_SLL_TARGET)

dll_shared: $(SHARED_DLL_TARGET)

sll: $(SLL_TARGET)

dll: $(DLL_TARGET)

all: $(SLL_TARGET) $(DLL_TARGET)

$(SLL_TARGET): singlelinkedlist.o s_main.c
	$(CC) $(CFLAGS) singlelinkedlist.o s_main.c -o $(SLL_TARGET)

singlelinkedlist.o: singlelinkedlist.c singlelinkedlist.h
	$(CC) $(CFLAGS) -c singlelinkedlist.c

$(DLL_TARGET): doublelinkedlist.o d_main.c
	$(CC) $(CFLAGS) doublelinkedlist.o d_main.c -o $(DLL_TARGET)

doublelinkedlist.o: doublelinkedlist.c doublelinkedlist.h
	$(CC) $(CFLAGS) -c doublelinkedlist.c

	
$(SHARED_SLL_TARGET): singlelinkedlist.c singlelinkedlist.h
	$(CC) -shared -o libsll.so -fPIC singlelinkedlist.c
	
$(SHARED_DLL_TARGET): doublelinkedlist.c doublelinkedlist.h
	$(CC) -shared -o libdll.so -fPIC doublelinkedlist.c
clean:
	rm -rf *.o *~ $(SLL_TARGET) $(DLL_TARGET) $(SHARED_SLL_TARGET).so $(SHARED_DLL_TARGET).so