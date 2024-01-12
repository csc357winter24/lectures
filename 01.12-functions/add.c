#include <stdio.h>

int main(void) {
    printf("The sum of 1 and 2 is %d\n", add(1, 2));
    printf("The sum of 3 and 4 is %d\n", add(3, 4));

    return 0;
}

int add(int x, int y) {
    int z = x + y;

    return z;
}
