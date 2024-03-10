CFLAGS = -Wall -Wextra -std=gnu11 -pedantic

all: client server 

debug: CFLAGS += -g
debug: clean all

client: client.o
	gcc -o client client.o

server: server.o
	gcc -o server server.o

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	rm -f *.o
