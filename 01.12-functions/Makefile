# NOTE: Header files are dependencies -- if we change some of the shared info,
#       we probably need to recompile -- but they are not part of the compiler
#       command. By the time the compiler sees the source files, any header
#       files will already have been copy-pasted into the source files.

# To compile object files into a named executable file:
add: main.o add.o
	gcc -o add main.o add.o

# To compile a source file into an object file:
main.o: main.c add.h
	gcc -Wall -Wextra -Werror -ansi -pedantic -c main.c

add.o: add.c add.h
	gcc -Wall -Wextra -Werror -ansi -pedantic -c add.c
