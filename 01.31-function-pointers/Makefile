reduce: reduce.o add.o add.h mult.o mult.h
	gcc -o reduce reduce.o add.o mult.o

reduce.o: reduce.c
	gcc -Wall -Wextra -Werror -ansi -pedantic -c reduce.c

add.o: add.c
	gcc -Wall -Wextra -Werror -ansi -pedantic -c add.c

mult.o: mult.c
	gcc -Wall -Wextra -Werror -ansi -pedantic -c mult.c
