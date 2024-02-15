#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fd;

    /* If open fails, it will return -1, and it will set the global variable
     *  errno to indicate the reason for the failure; perror will use that
     *  variable to print a human-readable message to stderr: */
    if ((fd = open("dne.txt", O_RDONLY)) < 0) {
        perror("open");
        /* return EXIT_FAILURE; */
    }

    /* If open fails for a different reason, perror 
    if ((fd = open("testdir", O_WRONLY)) < 0) {
        perror("open");
        /* return EXIT_FAILURE; */
    }

    close(fd);

    /* In all likelihood, this is 0, but for portability we're technically
     *  not supposed to assume that it will be 0: */
    return EXIT_SUCCESS;
}
