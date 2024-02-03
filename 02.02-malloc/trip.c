#include <stdlib.h>
#include <stdio.h>

int *trip(int, int, int);

int main(void) {
    int *arr, x;

    arr = trip(1, 2, 3);

    printf("arr: %p\n", (void *)arr);
    printf(" |- %p: %d\n", (void *)&arr[0], arr[0]);
    printf(" |- %p: %d\n", (void *)&arr[1], arr[1]);
    printf(" +- %p: %d\n", (void *)&arr[2], arr[2]);

    /* To deallocate dynamically alloacted space -- the compiler has no way of
     *  knowing when we no longer need this space, so we have to free it
     *  manually. Failing to do so is a memory leak: */
    free(arr);

    /* Freeing something twice is undefined:
     * free(arr); */

    /* Freeing only part of a block is also undefined:
     * free(arr + 1); */

    arr = &x;
    arr[0] = 1;

    /* Freeing something that isn't on the heap is also undefined:
     * free(arr); */

    return 0;
}

int *trip(int a, int b, int c) {
    int *arr;

    /* To allocate space for three integers on the heap -- this memory is
     *  independent of the conventions of the runtime stack, and will not be
     *  deallocated on return, so a pointer to it is safe to return: */
    arr = (int *)malloc(sizeof(int) * 3);

    arr[0] = a;
    arr[1] = b;
    arr[2] = c;

    return arr;
}
