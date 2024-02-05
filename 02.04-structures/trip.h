/* Anyone who includes trip.h will get a copy of pair.h also: */
#include "pair.h"

/* Trip: Represents a triple of integers. */
typedef struct Trip {
    Pair pair;
    int third;
} Trip;
