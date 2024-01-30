#include <stdio.h>

int main(void) {
    /* This declares a string on the runtime stack: */
    char str[] = "bar";

    printf("str: %p\n", (void *)str);
    printf(" |- %p: '%c'\n", (void *)&str[0], str[0]);
    printf(" |- %p: '%c'\n", (void *)&str[1], str[1]);
    printf(" |- %p: '%c'\n", (void *)&str[2], str[2]);
    printf(" +- %p: '%c'\n", (void *)&str[3], str[3]);
}
