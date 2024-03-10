#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int ptoc[2], ctop[2];

    /* In theory, we could just make one pipe, give everyone access to both
     *  ends, and then somehow coordinate who reads and who writes at what
     *  times. But in practice, we should just make two pipes. */

    pipe(ptoc);
    pipe(ctop);

    if (!fork()) {
        dup2(ptoc[0], STDIN_FILENO);
        dup2(ctop[1], STDOUT_FILENO);

        close(ptoc[0]);
        close(ptoc[1]);
        close(ctop[0]);
        close(ctop[1]);

        execlp("./hello", "./hello", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    else {
        char buf[81];
        int n;

        close(ptoc[0]);
        close(ctop[1]);

        /* At this point, both parent and child plan to send and receive data
         *  to and from one another, but they can't both start by receiving,
         *  otherwise they would be deadlocked waiting on other to send.
         *  Someone has to send first just to get the data flowing. */

        write(ptoc[1], "world\n", 6);
        close(ptoc[1]);

        n = read(ctop[0], buf, 80);
        buf[n] = '\0';
        printf("Child printed:\n%s\n", buf);
        close(ctop[0]);

        wait(NULL);
    }

    return EXIT_SUCCESS;
}
