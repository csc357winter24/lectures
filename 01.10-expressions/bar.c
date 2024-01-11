#include <stdio.h>

int main(void) { 
    /* This int only guarantees 16 bits: */
    short int x;

    /* This value is unknown, since "x" is uninitialized: */
    printf("%d\n", x);

    /* This will overflow; it doesn't fit in 16 bits: */
    x = 32768;
    printf("%d\n", x);

    x = 1;
    printf("x / 2: %f\n", (double)(x / 2));
    printf("x / 2.0: %f\n", x / 2.0);

    /* This is valid syntax and defined behavior, but it probably does not do
     *  what we intended; it compares a boolean to an integer: */
    x = 3;
    printf("1 < x < 2: %d\n", 1 < x < 2);

    /* ...this compares integers to integers, as intended: */
    printf("1 < x && x < 2: %d\n", 1 < x && x < 2);

    /* This is not allowed in ANSI C; variables must be declared as soon as
     *  they come into scope:
     * int z = 4; */

    /* This creates a new local scope: */
    {
        int z = 4;
        printf("z (inside): %d\n", z);

        /* This accesses the "x" in the nearest enclosing scope: */
        x = 5;
        printf("x (inside): %d\n", x);

        {
            /* This "shadows" the "z" in the enclosing scope: */
            int z = 6;
            printf("z (inside): %d\n", z);
        }
        printf("z (outside): %d\n", z);
    }

    /* This does not compile; "z" is not defined in this scope:
     *  printf("z (outside): %d\n", z); */
    printf("x (outside): %d\n", x);

    /* This never runs: */
    while (2 < 1) {
        printf("while 2 < 1...\n");
    }

    /* This runs exactly once: */
    do {
        printf("do while 2 < 1...\n");
    } while (2 < 1);

    /* This runs infinitely: */
    for (;;);

    return 0;
}
