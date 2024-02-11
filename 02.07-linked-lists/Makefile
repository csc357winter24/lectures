# Arguably, the -Werror flag is only meaningful when we are done and ready to
#  ship off the final version of our code; it's fine if there are warnings
#  as we incrementally develop, as long as we address them eventually:
CFLAGS = -Wall -Wextra -ansi -pedantic

list.o: list.c list.h
	gcc $(CFLAGS) -Werror -c list.c

debug:
	gcc $(CFLAGS) -g list.c listtests.c

test: debug
	valgrind --leak-check=full --show-leak-kinds=all ./a.out
