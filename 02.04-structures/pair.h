/* Pair: Represents a pair of integers. */
struct Pair {
    int first;
    int second;
};

/* The type defined by the above definition is "struct Pair", not "Pair"; if we
 *  wish to refer to it as simply "Pair", we can introduce a new name: */
typedef struct Pair Pair;
