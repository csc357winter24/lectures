#include <stdio.h>

/* To declare a function that takes an array of pointers as argument: */
void foo(int **mat) {
    mat[1][1] = 5;
}

/* To declare a function that takes an n x 2 array of integers as argument: */
void bar(int mat[][2]) {
    mat[1][1] = 6;
}

/* To declare a function that takes an n x m array of integers as argument: */
void bay(int *mat, int width) {
    mat[1 * width + 1] = 7;
}

int main(void) {
    /* To declare an array of two pointers to integers: */
    int r0[] = {1, 2}, r1[] = {3, 4};
    int *mat1[2];

    /* To declare a 2 x 2 array of integers: */
    int mat2[][2] = {{1, 2}, {3, 4}};

    mat1[0] = r0;
    mat1[1] = r1;
    foo(mat1);

    printf("mat1: %p\n", (void *)mat1);
    printf(" |- %p: %p\n", (void *)&mat1[0], (void *)mat1[0]);
    printf(" |----- %p: %d\n", (void *)&mat1[0][0], mat1[0][0]);
    printf(" |----- %p: %d\n", (void *)&mat1[0][1], mat1[0][1]);
    printf(" |- %p: %p\n", (void *)&mat1[1], (void *)mat1[1]);
    printf(" |----- %p: %d\n", (void *)&mat1[1][0], mat1[1][0]);
    printf(" +----- %p: %d\n", (void *)&mat1[1][1], mat1[1][1]);

    bar(mat2);
    bay((int *)mat2, 2);

    printf("mat2: %p\n", (void *)mat2);
    printf(" |- %p: %p\n", (void *)&mat2[0], (void *)mat2[0]);
    printf(" |----- %p: %d\n", (void *)&mat2[0][0], mat2[0][0]);
    printf(" |----- %p: %d\n", (void *)&mat2[0][1], mat2[0][1]);
    printf(" |- %p: %p\n", (void *)&mat2[1], (void *)mat2[1]);
    printf(" |----- %p: %d\n", (void *)&mat2[1][0], mat2[1][0]);
    printf(" +----- %p: %d\n", (void *)&mat2[1][1], mat2[1][1]);

    return 0;
}
