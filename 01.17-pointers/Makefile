swap: main.o swap.o
	gcc -o swap main.o swap.o

main.o: main.c swap.h
	gcc -Wall -Wextra -Werror -ansi -pedantic -c main.c

swap.o: swap.c swap.h
	gcc -Wall -Wextra -Werror -ansi -pedantic -c swap.c
