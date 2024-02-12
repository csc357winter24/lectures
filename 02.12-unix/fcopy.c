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

    while ((n = fread(buf, sizeof(char), SIZE, src)) > 0) {
        fwrite(buf, sizeof(char), n, dest);
    }

    fclose(src);
    fclose(dest);

    return 0;
}
