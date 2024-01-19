#include <stdio.h>
#include "rev.h"

#define LENGTH 4

int main(void) {
    /* To declare an array of four integers, where the first is 1 and the
     *  second is 2 (the compiler will zero out the rest): */
    int arr[LENGTH] = {1, 2};

    rev(arr, LENGTH);
    printf("arr: %p\n", (void *)arr);
    printf(" |- %p: %d\n", (void *)&arr[0], arr[0]);
    printf(" |- %p: %d\n", (void *)&arr[1], arr[1]);
    printf(" |- %p: %d\n", (void *)&arr[2], arr[2]);
    printf(" +- %p: %d\n", (void *)&arr[3], arr[3]);

    return 0;
}
