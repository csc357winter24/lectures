/* To copy-paste the contents of a file in the standard library: */
#include <stdio.h>

/* To copy-paste the contents of a file in the current working directory: */
#include "add.h"

int main(void) {
    int x, y;

    printf("Enter an integer: ");
    scanf("%d", &x);

    printf("Enter an integer: ");
    scanf("%d", &y);

    /* To apply a function that takes two integers and returns an integer: */
    printf("The sum of %d and %d is %d.\n", x, y, add(x, y));

    return 0;
}

