#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[16];

    /* Note that this process is entirely unaware that pipes might exist. It
     *  simply interacts with stdin and stdout. If we want to communicate with
     *  it from another process, we will have to "trick" it into thinking that
     *  pipes are actually stdin and/or stdout. */

    while (fgets(buf, 16, stdin) != NULL) {
        buf[strlen(buf) - 1] = '\0';
        printf("Hello, %s!\n", buf);
    }

    return 0;
}
