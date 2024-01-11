#include <stdio.h>

int main(void) {
    /* This int only guarantees 16 bits: */
    short int x;

    /* This int only contains non-negatives: */
    unsigned int y;

    /* This will overflow; 32768 does not fit in 16 signed bits: */
    x = 32768;
    printf("%d\n", x);

    /* This prints an unknown value; the variable is uninitialized: */
    printf("%d\n", y);

    /* This will not compile; x is an int, not a string: */
    /* x = "0"; */

    /* This will silently truncate the fractional portion: */ 
    x = 1.75;
    printf("%d\n", x);

    /* This will perform integer division: */
    printf("x / 2: %f\n", (double)(x / 2));

    /* This will perform floating point division: */
    printf("x / 2.0: %f\n", x / 2.0);

    /* This is almost certainly not what we intended; it compares a boolean
     *  to an integer: */
    x = 3;
    printf("1 < x < 2: %d\n", 1 < x < 2);
    printf("(1 < x) < 2: %d\n", (1 < x) < 2);

    /* This combines two booleans, as intended: */
    printf("1 < x && x < 2: %d\n", 1 < x && x < 2);
    
    /* This will not compile; variables can only be declared after a brace: */
    /* int z = 4; */

    /* This introduces a new local scope: */
    {
        int z = 4;
        printf("z (inside): %d\n", z);

        /* This will use the "y" from the nearest enclosing scope: */
        y = 5;
        printf("y (inside): %d\n", y);

        {
            /* This "shadows" the "x" in the enclosing scope: */
            int x = 6;
            printf("x (inside): %d\n", x);
        }
    }

    /* This will not compile; there is no "z" in this scope: */
    /* printf("z (outside): %d\n", z); */
    printf("y (outside): %d\n", y);
    printf("x (outside): %d\n", x);

    /* This never runs: */
    while (y < x) {
        printf("while y < x...\n");
    }

    /* This runs exactly once: */
    do {
        printf("do while y < x...\n");
    } while (y < x);

    /* This is an infinite loop: */
    for (;;);

    return 0;
}
