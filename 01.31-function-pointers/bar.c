#include <stdio.h>

int main(void) {
    /* This declares a string on the runtime stack: */
    char str1[] = "bar";

    /* This declares a pointer to a string in the read-only data segment: */
    char *str2 = "bar";

    /* This mutates a string on the runtime stack: */
    str1[2] = 'y';

    /* This fails at runtime since the string is read-only:
     * str2[2] = 'y'; */

    printf("str1: %p\n", (void *)str1);
    printf(" |- %p: '%c'\n", (void *)&str1[0], str1[0]);
    printf(" |- %p: '%c'\n", (void *)&str1[1], str1[1]);
    printf(" |- %p: '%c'\n", (void *)&str1[2], str1[2]);
    printf(" +- %p: %d\n", (void *)&str1[3], str1[3]);

    printf("str2: %p\n", (void *)str2);
    printf(" |- %p: '%c'\n", (void *)&str2[0], str2[0]);
    printf(" |- %p: '%c'\n", (void *)&str2[1], str2[1]);
    printf(" |- %p: '%c'\n", (void *)&str2[2], str2[2]);
    printf(" +- %p: %d\n", (void *)&str2[3], str2[3]);
}
