/* Node: Represents an element in a linked list. */
typedef struct Node {
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
int lstadd(List *, int, void *);
void *lstremove(List *, int);
