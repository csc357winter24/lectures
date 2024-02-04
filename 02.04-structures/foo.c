#include <stdio.h>
#include "pair.h"

int main(void) {
    struct Pair pair = {1, 2};

    printf("pair (%p):\n", (void *)&pair);
    printf(" |- first  (%p): %d\n", (void *)&pair.first, pair.first);
    printf(" +- second (%p): %d\n", (void *)&pair.second, pair.second);

    return 0;
}
