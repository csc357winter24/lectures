#include <stdio.h>

/* To define a rule that replaces every instance of "PI" with "3.14": */
#define PI 3.14

/* To define a rule that takes arguments -- note the lack of a trailing
 *  semicolon, since we don't know if this will be part of a larger expr.: */
#define ADD(X, Y) ((X) + (Y))

/* Recall the following function: */
int add(int x, int y) {
    return x + y;
}

int main(void) {
    /* This fails to compile, it expands to "3.14 = 3.14159265", which is
     *  nonsensical; 3.14 cannot be assigned a new value:
     * PI = 3.14159265; */

    /* This expands to "3.14 * 2" before compiling: */
    printf("PI * 2: %f\n", PI * 2);

    printf("add(1, 2): %d\n", add(1, 2));
    printf("ADD(1, 2): %d\n", ADD(1, 2));

    return 0;
}
