rev: main.o rev.o
	gcc -o rev main.o rev.o

main.o: main.c rev.h
	gcc -Wall -Wextra -Werror -ansi -pedantic -c main.c

rev.o: rev.c rev.h
	gcc -Wall -Wextra -Werror -ansi -pedantic -c rev.c
