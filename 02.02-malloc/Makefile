trip: trip.o
	gcc -o trip trip.o

trip.o: trip.c
	gcc -Wall -Wextra -Werror -ansi -pedantic -c trip.c

# NOTE: The -g flag instructs the compiler to include debug information, which
#       is not actually needed for the final (correct) executable:
debug: trip.c
	gcc -Wall -Wextra -Werror -ansi -pedantic -g -o trip trip.c
