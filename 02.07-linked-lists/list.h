/* Node: Represents an element in a linked list. */
typedef struct Node {
    /* In order for this list to contain data of any type, the values must be
     *  void pointers -- pointers that can point to anything: */
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
