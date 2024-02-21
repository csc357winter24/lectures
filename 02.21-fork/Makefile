CFLAGS = -Wall -Wextra -std=gnu11 -pedantic

all: search

debug: CFLAGS += -g
debug: clean all

search: search.o
	gcc -o search search.o

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	rm -f *.o
