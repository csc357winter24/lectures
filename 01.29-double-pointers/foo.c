#include <stdio.h>

int main(void) {
    int r0[] = {1, 2}, r1[] = {3, 4};
    int *mat[2];

    mat[0] = r0;
    mat[1] = r1;

    printf("mat: %p\n", (void *)mat);
    printf(" |- %p: %p\n", (void *)&mat[0], (void *)mat[0]);
    printf(" |----- %p: %d\n", (void *)&mat[0][0], mat[0][0]);
    printf(" |----- %p: %d\n", (void *)&mat[0][1], mat[0][1]);
    printf(" |- %p: %p\n", (void *)&mat[1], (void *)mat[1]);
    printf(" |----- %p: %d\n", (void *)&mat[1][0], mat[1][0]);
    printf(" +----- %p: %d\n", (void *)&mat[1][1], mat[1][1]);

    return 0;
}
