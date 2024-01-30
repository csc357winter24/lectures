#include <stdio.h>

/* To take an array of two integer pointers as argument -- the value of an array
 *  is a reference to its first element, thus, a reference to an integer pointer
 *  is passed as a double pointer: */
void foo(int **mat) {
    mat[1][1] = 7;
}

/* To take a two-dimensional array of two columns as argument -- note that this
 *  only works on arrays with exactly two columns: */
void bar(int mat[][2]) {
    mat[1][1] = 8;
}

/* To take a two-dimensional array of arbitrarily many columns -- note that the
 *  compiler is no longer aware that this (single) pointer refers to a 2D array,
 *  so the indexing math must be done manually: */
void bay(int *mat, int width) {
    mat[1 * width + 1] = 9;
}

int main(void) {
    /* To declare an array of two integer pointers, each of which will point
     *  to an array of integers: */
    int r0[] = {1, 2}, r1[] = {3, 4};
    int *mat1[2];

    /* To declare a two-dimensional array of 2x2 integers: */
    int mat2[][2] = {{1, 2}, {3, 4}};

    mat1[0] = r0;
    mat1[1] = r1;
    foo(mat1);

    /* NOTE: To make the indexing math work out in a true two-dimensional array,
     *       every row must have the same compile-time constant length, and a
     *       row cannot be swapped out for another row at runtime. */

    printf("mat1: %p\n", (void *)mat1);
    printf(" |- %p: %p\n", (void *)&mat1[0], (void *)mat1[0]);
    printf(" |----- %p: %d\n", (void *)&mat1[0][0], mat1[0][0]);
    printf(" |----- %p: %d\n", (void *)&mat1[0][1], mat1[0][1]);
    printf(" |- %p: %p\n", (void *)&mat1[1], (void *)mat1[1]);
    printf(" |----- %p: %d\n", (void *)&mat1[1][0], mat1[1][0]);
    printf(" +----- %p: %d\n", (void *)&mat1[1][1], mat1[1][1]);

    bar(mat2);
    bay((int *)mat2, 2);

    printf("\nmat2: %p\n", (void *)mat2);
    printf(" |- %p: %p\n", (void *)&mat2[0], (void *)mat2[0]);
    printf(" |----- %p: %d\n", (void *)&mat2[0][0], mat2[0][0]);
    printf(" |----- %p: %d\n", (void *)&mat2[0][1], mat2[0][1]);
    printf(" |- %p: %p\n", (void *)&mat2[1], (void *)mat2[1]);
    printf(" |----- %p: %d\n", (void *)&mat2[1][0], mat2[1][0]);
    printf(" +----- %p: %d\n", (void *)&mat2[1][1], mat2[1][1]);

    return 0;
}
