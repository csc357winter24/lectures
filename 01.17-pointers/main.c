#include <stdio.h>
#include "swap.h"

int main(void) {
    int z = 1, w = 2;

    /* To call a function passing two integer pointers as arguments: */
    swap(&z, &w);
    printf("z (%p): %d\n", (void *)&z, z);
    printf("w (%p): %d\n", (void *)&w, w);

    return 0;
}

