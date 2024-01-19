#include "rev.h"

/* To define a function that takes as argument an array of integers -- note
 *  that the length must be passed separately: */
void rev(int arr[], int len) {
    int i;

    /* Since an array is an address, its value is a reference, and this will
     *  modify the caller's copy: */
    for (i = 0; i < len / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = temp;
    }
}
