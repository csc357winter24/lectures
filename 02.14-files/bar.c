#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fd;

    /* If open fails, it will return -1 and set errno to indicate the reason
     *  for the failure; perror will use errno to print a human-readable error
     *  message. */
    if ((fd = open("foo.txt", O_RDONLY)) < 0) {
        perror("open");
        /* return EXIT_FAILURE; */
    }

    /* Different calls to open may fail for different reasons; errno will be
     *  set accordingly, and perror knows the diference. */
    if ((fd = open("testdir", O_WRONLY)) < 0) {
        perror("open");
        /* return EXIT_FAILURE; */
    }

    /* For portability, we should not assume that this will be 0: */
    return EXIT_SUCCESS;
}
