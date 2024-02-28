CFLAGS = -Wall -Wextra -std=gnu11 -pedantic

all: clock sporkbomb

debug: CFLAGS += -g
debug: clean all

clock: clock.o
	gcc -o clock clock.o

sporkbomb: spork.o sporkbomb.o spork.h
	gcc -o sporkbomb spork.o sporkbomb.o

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	rm -f *.o
