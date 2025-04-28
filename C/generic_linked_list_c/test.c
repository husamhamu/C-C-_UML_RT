#include <stdio.h>

#include "list.h"

int main() {
    List* list = list_init(sizeof(int));
    int* elem;

    elem = list_prepend(list);
    *elem = 1;
    elem = list_append(list);
    *elem = 2;
    elem = list_insert_after(list, elem);
    *elem = 4;
    elem = list_insert_before(list, elem);
    *elem = 3;
    elem = list_insert_after(list, list_last(list));
    *elem = 5;

    /* print 1 2 3 4 5 */
    LIST_FOREACH(elem, list) {
        printf("%d ", *elem);
    }
    printf("\n");

    /* print 5 4 3 2 1 */
    LIST_FOREACH_REVERSED(elem, list) {
        printf("%d ", *elem);
    }
    printf("\n");

    list_delete(list);

    return 0;
}
