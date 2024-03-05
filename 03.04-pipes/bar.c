#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fds[2];

    /* A pipe is essentially a temporary file, but it is managed by the OS and
     *  isn't stored on disk; it can't be opened like a normal file. It must
     *  be created prior to forking so that it can be inherited. */
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
        /* No longer just as a matter of best practice, but also to ensure we
         *  don't trick other processes into thinking we're using a pipe when
         *  we're not, we ought to close these descriptors AS SOON as we know
         *  we no longer need them: */
        close(fds[0]);

        printf("%d wrote to pipe.\n", getpid());
        write(fds[1], "Hello, child!", 13);

        /* Closing the write-end of this pipe is how the child will know that
         *  there is no more data coming: */
        close(fds[1]);
        wait(NULL);
    }


    return EXIT_SUCCESS;
}
