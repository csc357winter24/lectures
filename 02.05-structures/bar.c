#include <stdio.h>
#include "trip.h"

Pair foo(Pair pair) {
    pair.first = 0;
    pair.second = 0;

    return pair;
}

void bar(Pair *pair) {
    /* The dot has precedence over the star; without the parentheses, this
     *  would be attempting to access a pointer IN a struct rather than a
     *  pointer TO a struct: */
    (*pair).first = 0;

    /* Alternatively, the arrow is equivalent to a star and then a dot: */
    pair->second = 0;
}

int main(void) {
    Pair pair = {1, 2};
    Trip trip = {{3, 4}, 5};

    /* Since we have defined a new type, the compiler has no idea how to
     *  operate on values of that type. The only operations supported are
     *  ".", "=", and "&": */
    trip.pair = foo(pair);
    bar(&pair);

    /* ...for example, if we want to print out a value of this new type, we
     *  must do so manually: */
    printf("pair (%p):\n", (void *)&pair);
    printf(" |- first  (%p): %d\n", (void *)&pair.first, pair.first);
    printf(" +- second (%p): %d\n", (void *)&pair.second, pair.second);

    printf("trip (%p):\n", (void *)&trip);
    printf(" |- pair   (%p):\n", (void *)&trip.pair);
    printf(" |----- first  (%p): %d\n", (void *)&trip.pair.first, trip.pair.first);
    printf(" |----- second (%p): %d\n", (void *)&trip.pair.second, trip.pair.second);
    printf(" +- third  (%p): %d\n", (void *)&trip.third, trip.third);

    return 0;
}
