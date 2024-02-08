CFLAGS = -Wall -Wextra -ansi -pedantic

list.o: list.c list.h
	gcc $(CFLAGS) -Werror -c list.c

# Arguably, the -Werror flag is only meaningful once we go to ship the final
#  version of our code; it's fine if there are warnings while we develop and
#  test, as long as we get to them eventually:
test:
	gcc $(CFLAGS) list.c listtests.c
	./a.out

debug:
	gcc $(CFLAGS) -g list.c listtests.c
	valgrind --leak-check=full --show-leak-kinds=all ./a.out
