#include <stdio.h>
#include "swap.h"

int main(void) {
    int z = 1, w = 2;

    swap(z, w);
    printf("z: %d, w: %d\n", z, w);

    return 0;
}

