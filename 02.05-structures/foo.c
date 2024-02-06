#include <stdio.h>
#include "trip.h"

/* To define a function that takes a struct as argument and produces a struct
 *  as return value -- note that the value of a struct is the whole struct: */
Pair foo(Pair pair) {
    pair.first = 0;
    pair.second = 0;

    return pair;
}

/* To define a function that takes a pointer to a struct as argument: */
void bar(Pair *pair) {
    /* Without the parentheses, the dot would have precedence, and this would
     *  attempt to dereference a pointer IN a struct, rather than a pointer
     *  TO a struct: */
    (*pair).first = 3;

    /* Alternatively, the arrow operator is equivalent to star, then dot: */
    pair->second = 4;
}

int main(void) {
    Pair pair = {1, 2};
    Trip trip = {{1, 2}, 3};

    /* Since we have defined a new type, the compiler has no way of knowing how
     *  to operate on it. The only allowable operations are "=", ".", "&": */
    pair = foo(pair);
    bar(&pair);
    trip.pair = pair;

    /* ...if, for example, we want to print a value of this new type, we have
     *  to do it manually: */
    printf("pair (%p):\n", (void *)&pair);
    printf(" |- first  (%p): %d\n", (void *)&pair.first, pair.first);
    printf(" +- second (%p): %d\n", (void *)&pair.second, pair.second);

    printf("trip (%p):\n", (void *)&trip);
    printf(" |- pair   (%p):\n", (void *)&trip.pair);
    printf(" |----- first  (%p): %d\n", (void *)&trip.pair.first, trip.pair.first);
    printf(" |----- second (%p): %d\n", (void *)&trip.pair.second, trip.pair.second);
    printf(" +- third (%p): %d\n", (void *)&trip.third, trip.third);

    return 0;
}
