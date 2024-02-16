CFLAGS = -Wall -Wextra -std=gnu11 -pedantic

all: list

debug: CFLAGS += -g
debug: clean all

list: list.o
	gcc -o list list.o

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	rm -f *.o
