#include <stdlib.h>
#include "list.h"

/* lstcreate: Creates an empty linked list. */
List *lstcreate() {
    List *lst = (List *)malloc(sizeof(List));

    /* The compiler and standard library do not and cannot know what a List is
     *  or how it should be initialized -- this is just 12 random bytes. */
    lst->head = NULL;
    lst->size = 0;

    return lst;
}

/* lstdestroy: Destroys an existing linked list. */
void lstdestroy(List *lst) {
    /* TODO: This only frees the List itself; also need to free the Nodes
     *       within it... */
    free(lst);
}

/* lstget: Gets an element in a linked list. */
void *lstget(List *lst, int idx) {
    return NULL;
}

/* lstset: Sets an element in a linked list. */
int lstset(List *lst, int idx, void *value) {
    return 0;
}

/* lstadd: Adds an element to a linked list. */
int lstadd(List *lst, int idx, void *value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;

    if (idx == 0) {
        node->next = lst->head;
        lst->head = node;
    }
    else {
        Node *tmp = lst->head;
        int i;

        for (i = 0; i < idx - 1; i++) {
            tmp = tmp->next;
        }

        node->next = tmp->next;
        tmp->next = node;
    }

    lst->size++;

    /* If we wanted to check for indexing out-of-bounds, we might return
     *  something other than 0 if idx < 0 or idx > lst->size. */
    return 0;
}

/* lstremove: Removes an element from a linked list. */
void *lstremove(List *lst, int idx) {
    return NULL;
}
