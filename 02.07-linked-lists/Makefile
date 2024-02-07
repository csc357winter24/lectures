list.o: list.c list.h
	gcc -Wall -Wextra -Werror -ansi -pedantic -c list.c

# Arguably, the -Werror flag is only meaningful once we go to ship the final
#  version of our code; it's fine if there are warnings while we develop and
#  test, as long as we get to them eventually:
test:
	gcc -Wall -Wextra -ansi -pedantic list.c listtests.c
	./a.out
