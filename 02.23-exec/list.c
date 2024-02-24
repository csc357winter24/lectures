#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    /* Rather than listing the contents of a directory ourselves, we could fork
     *  a child and then replace that child with "ls", which already knows how
     *  to list directories' contents. */
    if (!fork()) {
        /* The child will be replaced with "ls". Recall that by convention,
         *  the first argument is always the name of the executble. */
        execlp("ls", "ls", "-a", argv[1], NULL);

        /* Assuming it succeeds, there is no returning from an exec; we have
         *  been replaced by a different executable. The only way to get here
         *  is if exec fails. */
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    else {
        /* The parent will remain unchanged, so that it knows to wait. */
        int status;

        wait(&status);
        if (!WIFEXITED(status) || WEXITSTATUS(status) != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        }
        else {
            return EXIT_SUCCESS;
        }
    }
}
