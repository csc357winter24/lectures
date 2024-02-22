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
            /* It is crucially important that the child DOES NOT go around to
             *  the next iteration of the loop; we do NOT want the child to
             *  make any grandchildren; we want it to return as soon as it is
             *  done with its search. */
            return fsearch(argv[i], argv[1]);
        }
        else {
            /* Although the parent must eventually wait for the child, doing
             *  so here would be no better than searching all of the files
             *  sequentially -- we want to move on to the next file instead
             *  of waiting. */
        }
    }

    for (i = 2; i < argc; i++) {
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
