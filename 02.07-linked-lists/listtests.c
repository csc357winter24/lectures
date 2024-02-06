#include <stddef.h>
#include <assert.h>
#include "list.h"

/* test01: Tests empty lists. */
void test01() {
    List *lst = lstcreate();

    assert(lst != NULL);
    assert(lst->head == NULL);
    assert(lst->size == 0);

    lstdestroy(lst);
}

/* test02: Tests adding to lists. */
void test02() {
    List *lst = lstcreate();

    lstadd(lst, 0, (void *)97);
    lstadd(lst, 1, (void *)98);

    assert(lst->head != NULL);
    assert(lst->head->value == (void *)97);
    assert(lst->head->next->value == (void *)98);
    assert(lst->head->next->next == NULL);
    assert(lst->size == 2);

    lstdestroy(lst);
}

/* test03: Tests removing from lists. */
void test03() {
    List *lst = lstcreate();

    lstadd(lst, 0, (void *)98);
    lstadd(lst, 1, (void *)99);
    lstadd(lst, 1, (void *)97);
    lstremove(lst, 1);
    lstadd(lst, 0, (void *)97);

    assert(lst->size == 3);
    assert(lstget(lst, 0) == (void *)97);
    assert(lstget(lst, 1) == (void *)98);
    assert(lstget(lst, 2) == (void *)99);

    lstdestroy(lst);
}

int main(void) {
    test01();
    test02();
    test03();

    return 0;
}
