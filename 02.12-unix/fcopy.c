/* Copies the contents of one file into another using standard library
 *  functions -- these functions provide additional abstractions on top of
 *  system calls, encapsulating the most commonly desired functionality. */

#include <stdio.h>

#define SIZE 16

int main(int argc, char *argv[]) {
    char buf[SIZE];
    int n;
    FILE *src, *dest;

    src = fopen(argv[1], "r");
    dest = fopen(argv[2], "w");

    /* Behind the scenes, fread maintains its own buffer -- it reads more
     *  characters than we initially ask for, so as to limit system calls.
     *  Future calls to fread will likely not call read; they'll just copy from
     *  fread's internal buffer. */
    while ((n = fread(buf, sizeof(char), SIZE, src)) > 0) {
        fwrite(buf, sizeof(char), n, dest);
    }

    fclose(src);
    fclose(dest);

    return 0;
}
