#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[16];

    while (fgets(buf, 16, stdin) != NULL) {
        buf[strlen(buf) - 1] = '\0';
        printf("Hello, %s!\n", buf);
    }

    return 0;
}
