#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fds[2];

    /* Create a pipe -- note that a pipe has no name, so it cannot be opened
     *  later like a normal file; it has to be created first so that the child
     *  can inherit these descriptors from the parent: */
    pipe(fds);

    if (!fork()) {
        char buf[5];
        int n;

        close(fds[1]);

        while ((n = read(fds[0], buf, 4)) > 0) {
            buf[n] = '\0';
            printf("%d read \"%s\" from pipe.\n", getpid(), buf);
        }

        close(fds[0]);
    }
    else {
        /* It is good practice to close an end of the pipe as soon as we know
         *  we no longer need it, so that other processes are informed that
         *  we aren't using it: */
        close(fds[0]);

        /* Even though the pipe is not truly a file, the OS allows us to
         *  interface with it as though it were a file, using the ordinary
         *  "read" and "write" system calls: */
        printf("%d writing to pipe.\n", getpid());
        write(fds[1], "Hello, child!", 13);

        /* Closing the write end of the pipe is the only way the child will
         *  know that we have no more data to send: */
        close(fds[1]);
        wait(NULL);
    }


    return EXIT_SUCCESS;
}
