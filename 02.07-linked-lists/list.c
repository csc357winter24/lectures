#include <stdlib.h>
#include "list.h"

/* lstcreate: Creates an empty linked list. */
List *lstcreate() {
    List *lst = (List *)malloc(sizeof(List));

    /* The standard library does not and cannot know what this dynamically
     *  allocated memory represents; it is our job to initialize it. */
    lst->head = NULL;
    lst->size = 0;

    return lst;
}

/* lstdestroy: Destroys an existing linked list. */
void lstdestroy(List *lst) {
    Node *tmp = lst->head;
    int i;

    for (i = 0; i < lst->size; i++) {
        /* Once we free tmp, we have idea what its memory contains, so if we
         *  care about tmp->next, we must save it first. */
        Node *next = tmp->next;
        free(tmp);
        tmp = next;
    }

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

    /* If, for example, idx < 0 or idx > lst->size, convention is to return
     *  a non-zero error code: */
    return 0;
}

/* lstremove: Removes an element from a linked list. */
void *lstremove(List *lst, int idx) {
    return NULL;
}
