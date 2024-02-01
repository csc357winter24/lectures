#include <stdio.h>
#include "add.h"
#include "mult.h"

/* To declare a function... */
int reduce(int [], int, int (*)(int, int));

int main(void) {
    int arr[] = {1, 2, 3, 4};

    /* To call a function... */
    printf("reduce(arr, 4, &add): %d\n", reduce(arr, 4, &add));
    printf("reduce(arr, 4, &mult): %d\n", reduce(arr, 4, &mult));

    return 0;
}

/* To define a function that takes as argument a pointer to another function,
 *  where that other function takes as argument two integers and produces as
 *  return value a third integer: */
int reduce(int arr[], int length, int (*fn)(int, int)) {
    int sum = arr[0], i;

    for (i = 1; i < length; i++) {
        /* To call the function that was taken as an argument: */
        sum = (*fn)(sum, arr[i]);
    }

    return sum;
}
