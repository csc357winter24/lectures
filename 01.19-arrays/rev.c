#include "rev.h"

/* To define a function that takes as argument an array of integers -- note
 *  that the length must be taken as a separate argument: */
void rev(int arr[], int len) {
    int i;

    /* Note that the value of an array is a reference to the first element, so
     *  changes here will be reflected in the caller's copy: */
    for (i = 0; i < len / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = temp;
    }
}
