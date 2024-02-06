/* Anyone who includes trip.h will also get a copy of pair.h: */
#include "pair.h"

/* Trip: Represents a triple of integers. */
typedef struct Trip {
    Pair pair;
    int third;
} Trip;
