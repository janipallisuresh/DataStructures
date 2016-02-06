# Build and Execute.
<b>HOW TO BUILD EXECUTABLES: </b>

You can use below make command which generates the executables.
  - make all - To build all the programs.
Following executables are generated after 'make all'
  - singlelinkedlist, doublelinkedlist, queue, stack.
Run these executables.

To make Individual binaries please use the following commands.
  - make sll - To build Single linked list program.
  - make dll - To build double linked list program.
  - make queue - TO build Queue DS program
  - make stack - To Build Stack DS program.

<b>HOW TO COMPILE THEM USING GCC: </b>

Simply you can run following gcc command to build.
  - gcc singlelinkedlist.c s_main.c -o singlelinkedlist -Wall
  - gcc doublelinkedlist.c d_main.c -o doublelinkedlist -wall
  - gcc queue.c doublelinkedlist.c queue_main.c -o queue -wall
  - gcc stack.c singlelinkedlist.c stack_main.c -o stack -wall

<b>HOW TO BUILD AND LINK SHARED OBJECTS:</b>

You can build the shared objects and link them to your own executable.
  - make shared_all - generates libsll.so, libdll.so, libmyqueue.so and libmystack.so

To make Individual shared objects then use following commands.
  - make shared_sll - Generates libsll.so
  - make shared_dll - Generates libdll.so
  - make shared_myqueue - Generates libmyqueue.so
  - make shared_mystack - Generates libmystack.so

Now to link these you can use the following command.
  - gcc foo.c -L/path to shared object -lsll/dll -o foo
Example:
If your in the current directory where libsll.so/libdll.so is present then
  - gcc s_main.c -L./ -lsll -o s_main
Now run the executable
  - ./s_main - (you may have to add the path to libsll.so to your env variable LD_LIBRARY_PATH)

<i>For more detials please visit: http://janipallisuresh.github.io/MyDs_Doc/index.html </i>
