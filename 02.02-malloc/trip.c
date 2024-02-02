#include <stdlib.h>
#include <stdio.h>

int *trip(int, int, int);

int main(void) {
    int *arr;

    arr = trip(1, 2, 3);

    printf("arr: %p\n", (void *)arr);
    printf(" |- %p: %d\n", (void *)&arr[0], arr[0]);
    printf(" |- %p: %d\n", (void *)&arr[1], arr[1]);
    printf(" +- %p: %d\n", (void *)&arr[2], arr[2]);

    /* Since we allocated the memory pointed to by arr independently of the 
     *  compiler's conventions, we are responsible for deallocating it: */
    free(arr);

    return 0;
}

int *trip(int a, int b, int c) {
    int *arr;

    /* To allocate space for three integers on the heap, independently of the
     *  runtime stack, and thus safe to return: */
    arr = (int *)malloc(sizeof(int) * 3);

    arr[0] = a;
    arr[1] = b;
    arr[2] = c;

    return arr;
}
