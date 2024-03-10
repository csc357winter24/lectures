#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int ptoc[2], ctop[2];

    /* In theory, we could give every process access to a single pipe, and then
     *  find a way to coordinate who reads and who writes at what times, but we
     *  really should just make two pipes, one for each direction. */
    pipe(ptoc);
    pipe(ctop);

    if (!fork()) {
        /* By replaceing stdin and stdout with pipes, we "trick" the child
         *  process into using the pipes instead of the terminal. */
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
        char buf[128];
        int n;

        close(ptoc[0]);
        close(ctop[1]);

        /* At this point, both the parent and the child are planning to read
         *  and write to and from one another, but they can't BOTH read first,
         *  otherwise they'll be deadlocked waiting for the other to write.
         *  Someone has to write first just to get the data flowing... */

        write(ptoc[1], "world\n", 6);
        close(ptoc[1]);

        n = read(ctop[0], buf, 127);
        buf[n] = '\0';
        close(ctop[0]);

        printf("Child printed:\n%s\n", buf);

        wait(NULL);
    }

    return EXIT_SUCCESS;
}
