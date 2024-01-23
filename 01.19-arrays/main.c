#include <stdio.h>
#include "rev.h"

#define LENGTH 4

int main(void) {
    /* To declare an array of four integers; the first two are initialized to
     *  1 and 2, and the remaining are zeroed out: */
    int arr[LENGTH] = {1, 2};

    rev(arr, LENGTH);
    printf("arr: %p\n", (void *)arr);
    printf(" |- %p: %d\n", (void *)&arr[0], arr[0]);
    printf(" |- %p: %d\n", (void *)&arr[1], arr[1]);
    printf(" |- %p: %d\n", (void *)&arr[2], arr[2]);
    printf(" +- %p: %d\n", (void *)&arr[3], arr[3]);

    return 0;
}
