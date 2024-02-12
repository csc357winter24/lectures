# Now that we are programmers who know what we are doing, we can drop the
#  -Werror flag and switch to the latest C11 standard with the GNU extensions.
CFLAGS = -Wall -Wextra -std=gnu11 -pedantic

all: copy fcopy

# This adds -g to the CFLAGS variable when building the debug target:
debug: CFLAGS += -g
debug: clean all

copy: copy.o
	gcc -o copy copy.o

fcopy: fcopy.o
	gcc -o fcopy fcopy.o

# This instructs Make to build any .o file by using a .c file with the exact
#  same name:
%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	rm -f *.o
