list.o: list.c list.h
	gcc -Wall -Wextra -Werror -ansi -pedantic -c list.c

test: list.o
	gcc -Wall -Wextra -Werror -ansi -pedantic list.o listtests.c
	./a.out
