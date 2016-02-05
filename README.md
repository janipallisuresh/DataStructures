# Build and Execute.
HOW TO BUILD:

You can use below make command which generates the executable.
  - make all - To build all the programs.
  - make sll - To build Single linked list program.
  - make dll - To build double linked list program.

OR
Simply you can run following gcc command to build.
  - gcc singlelinkedlist.c s_main.c -o singlelinkedlist -Wall
  - gcc doublelinkedlist.c d_main.c -o doublelinkedlist -wall

HOW TO RUN:

The executables that generated are
  - singlelinkedlist
  - doublelinkedlist 

HOW TO BUILD AND LINK SHARED OBJECTS:

You can build the shared objects and link them to your own executable.

  - make sll_shared - Generates libsll.so
  - make dll_shared - Generated libdll.so
Now to link these you can use the following command.
  - gcc <foo.c> -L<path to shared object> -l<sll/dll> -o foo
Example:
If your in the current directory where libsll.so/libdll.so is present then
  - gcc s_main.c -L. -lsll -o s_main
Now run the executable
  - ./s_main - (you may have to add the path to libsll.so to your env variable LD_LIBRARY_PATH)

For more detials please visit: http://janipallisuresh.github.io/MyDs_Doc/index.html
