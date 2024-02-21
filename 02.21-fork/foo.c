#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    pid_t child;
    int status;

    /* fork will duplicate the current process; we call it once, but it
     *  returns twice. */
    if ((child = fork()) == 0) {
        /* This is the child process. */
        printf("%ld is the child of %ld\n", getpid(), getppid());

        return 94;
    }
    else {
        /* This is the parent process. */
        printf("%ld is the parent %ld\n", getpid(), child);

        /* It is the parent's responsibility to wait for all children before
         *  terminating -- until the parent waits for the child, the resources
         *  associated with the child cannot be completely deallocated. There
         *  is a finite limit on the number of processes a user can have, and
         *  if we never wait for our children, eventually we might run into
         *  that limit: */
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Child terminated with status %d\n", WEXITSTATUS(status));
        }

        return 0;
    }
}
