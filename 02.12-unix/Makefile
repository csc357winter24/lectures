CFLAGS = -Wall -Wextra -std=gnu11 -pedantic

all: copy fcopy

debug: CFLAGS += -g
debug: clean all

copy: copy.o
	gcc -o copy copy.o

fcopy: fcopy.o
	gcc -o fcopy fcopy.o

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	rm -f *.o
