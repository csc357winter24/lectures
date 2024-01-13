# NOTE: Header files are typically dependencies -- if we change a header file,
#       we probably need to recompile -- but they should not be named in the
#       compiler command. By the time the source files are compiled, the
#       contents of the header files will already have been copied into the
#       source files.

# To compile object files into a named executable file:
add: main.o add.o
	gcc -o add main.o add.o

# To compile a source file into an object file:
main.o: main.c add.h
	gcc -Wall -Wextra -Werror -ansi -pedantic -c main.c

add.o: add.c add.h
	gcc -Wall -Wextra -Werror -ansi -pedantic -c add.c
