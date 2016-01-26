CC=gcc
CFLAGS=-Wall -g
TARGET=sll

all: $(TARGET)

$(TARGET): singlelinkedlist.o main.c 
	$(CC) $(CFLAGS) singlelinkedlist.o main.c -o $(TARGET)

singlelinkedlist.o: singlelinkedlist.c singlelinkedlist.h
  $(CC) $(CFLAGS) -c singlelinkedlist.c

clean:
	rm -rf *.o *~ $(TARGET)
