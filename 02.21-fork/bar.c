#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    pid_t child;
    int status;

    if ((child = fork()) == 0) {
        /* This is within the child process. */
        printf("%ld is the child of %ld.\n", getpid(), getppid());

        return 94;
    }
    else {
        /* This is within the parent process. */
        printf("%ld is the parent of %ld.\n", getpid(), child);

        /* It is the parent's responsibility to wait for its children before
         *  itself terminating. Until the parent waits for the child, the
         *  resources associated with the child cannot be completely
         *  deallocated. If we continue to fork without ever waiting, there is
         *  a finite limit on the number of processes that we will eventually
         *  run up against. */
        wait(&status);

        if (WIFEXITED(status)) {
            printf("%ld exited with status %d.\n", child, WEXITSTATUS(status));
        }
        else {
            printf("%ld exited abnormally.\n", child);
        }

        return 0;
    }
}
