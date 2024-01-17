#include <stdio.h>

/* To replace every occurrence of "PI" with "3.14": */
# define PI 3.14

/* Recall the following function: */
int add(int x, int y) {
    return x + y;
}

/* To rewrite the above function as an equivalent macro -- note the lack of a
 *  trailing semicolon, which could be copied into a larger expression: */
#define ADD(X, Y) ((X) + (Y))

int main(void) {
    /* This fails to compile; it expands to "3.14 = 3.14159265", which is
     *  nonsensical: 
     * PI = 3.14159265; */

    /* This expands to "3.14 * 2": */
    printf("PI * 2: %f\n", PI * 2);

    /* This expands to "((1) + (2))": */
    printf("add(1, 2): %d\n", add(1, 2));
    printf("ADD(1, 2): %d\n", ADD(1, 2));

    /* This works with macros but not with functions: macros don't have any
     *  parameter types or return types, and this expands to the intended
     *  floating point arithmetic "((1.2) + (3.4))": */
    printf("add(1.2, 3.4): %f\n", (double)add(1.2, 3.4));
    printf("ADD(1.2, 3.4): %f\n", ADD(1.2, 3.4));
    
    return 0;
}
