#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* For simplicity, assume no line exceeds 80 characters. */
#define LINELEN 81

int fsearch(char *, char *);

int main(int argc, char *argv[]) {
    int i, status = EXIT_FAILURE, tmp;

    for (i = 2; i < argc; i++) {
        if (!fork()) {
            /* It is vitally important that we know which is the parent and
             *  which is the child -- the child cannot be allowed to loop
             *  again; the child must avoid forking any children of its own. */
            return fsearch(argv[i], argv[1]);
        }
        else {
            /* We don't want the parent to do anything just yet -- we will
             *  eventually need to wait for the child we just created, but we
             *  don't want to do that until all of the children have been
             *  created, otherwise this is no faster than just doing all the
             *  searches ourselves, one after the other... */
        }
    }

    /* Children return as soon as they finish their searches; so only the
     *  parent can make it this far in the control flow. */

    for (i = 2; i < argc; i++) {
        /* If we cared to know which child exited or what status it returned,
         *  we could do that here. */
        wait(NULL);
    }

    return status;
}

/* fsearch: Prints occurrences of a string in a file. */
int fsearch(char *fname, char *str) {
    int status = EXIT_FAILURE;
    char buf[LINELEN];
    FILE *file = fopen(fname, "r");

    while (fgets(buf, LINELEN, file) != NULL) {
        if (strstr(buf, str) != NULL) {
            printf("%s: %s", fname, buf);
            status = EXIT_SUCCESS;
        }
    }

    fclose(file);
    return status;
}
