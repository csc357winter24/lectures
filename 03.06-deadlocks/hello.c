#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[16];

    /* This program has no idea that pipes might be involved -- it simply
     *  expects to use stdin and stdout. We will have to replace stdin and/or
     *  stdout with pipes in order to "trick" this program into using the
     *  pipes instead... */

    while (fgets(buf, 16, stdin) != NULL) {
        buf[strlen(buf) - 1] = '\0';
        printf("Hello, %s!\n", buf);
    }

    return 0;
}
