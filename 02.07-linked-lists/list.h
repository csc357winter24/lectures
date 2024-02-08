/* Node: Represents an element in a linked list. */
typedef struct Node {
    /* A void pointer can point to anything -- if this were instead declared
     *  as an int, for example, then the list would only ever be able to
     *  contain ints. We don't know what it points to, but that's okay, because
     *  we just need to store it; we never need to dereference it. */
    void *value;
    struct Node *next;
} Node;

/* List: Represents a linked list. */
typedef struct List {
    Node *head;
    int size;
} List;

List *lstcreate();
void lstdestroy(List *);
void *lstget(List *, int);
int lstset(List *, int, void *);
int lstadd(List *, int, void *);
void *lstremove(List *, int);
