#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int status;

    if (!fork()) {
        /* This is the child process, which we will replace with the
         *  executable for "ls". */
        execlp("ls", "ls", "-a", argv[1], NULL);

        /* Assuming exec succeeds, there is no returning from an exec; the
         *  process has been entirely replaced with another. The only way to
         *  get this far is if the exec fails. */
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    else {
        /* This is the parent process, which must maintain its identity so that
         *  it knows to wait for the child. */
        wait(&status);

        if (!WIFEXITED(status) || WEXITSTATUS(status) != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        }
        else {
            return EXIT_SUCCESS;
        }
    }

    return EXIT_SUCCESS;
}
