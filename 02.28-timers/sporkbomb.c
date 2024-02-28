#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include "spork.h"

int main(void) {
    if (!spork(5)) {
        printf("Process %d is the child.\n", getpid());

        while (1) {
            int pid = fork();

            if (pid == 0) {
                printf("Process %d is a new child.\n", getpid());
            }
            else if (pid > 0) {
                printf("Process %d is a new parent.\n", getpid());
            }
            else {
                perror("fork");
            }

            sleep(1);
        }
    }
    else {
        int status;

        printf("Process %d is the parent.\n", getpid());
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Child exited with status %d.\n",
                   WEXITSTATUS(status));
        }
        else {
            printf("Child terminated abnormally.\n");
        }
    }

    return 0;
}
