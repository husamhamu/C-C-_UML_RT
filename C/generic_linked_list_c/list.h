#ifndef GENERIC_LIST_LIST_H
#define GENERIC_LIST_LIST_H

typedef struct List List;

/**
 * @param item_size Size of the items we want to store
 * @return new doubly linked list
 */
List* list_init(size_t item_size);

/**
 * @param list List
 * @return First item in list or NULL if the list is empty
 */
void* list_first(const List* list);

/**
 * @param list List
 * @return Last item in list or NULL if the list is empty
 */
void* list_last(const List* list);

/**
 * @param item An item that is in the list
 * @return The item that succeeds item in the list or NULL if item is the
 * last item
 */
void* list_next(const void* item);

/**
 * @param item An item that is in the list
 * @return The item that precedes item in the list or NULL if item is the
 * first item
 */
void* list_previous(const void* item);

/**
 * Iterate through all the items in the list
 * @param item Will be assigned the pointers of the contents of the list
 * @param list List
 */
#define LIST_FOREACH(item, list) \
    for (item = list_first(list); item != NULL; item = list_next(item))

/**
 * Iterate backwards through all the items in the list
 * @param item Will be assigned the pointers of the contents of the list
 * @param list List
 */
#define LIST_FOREACH_REVERSED(item, list) \
    for (item = list_last(list); item != NULL; item = list_previous(item))

/**
 * Insert a new item at the beginning of the list
 * @param list List
 * @return A pointer to the newly inserted item
 */
void* list_prepend(List* list);

/**
 * Insert a new item at the end of the list
 * @param list List
 * @return A pointer to the newly inserted item
 */
void* list_append(List* list);

/**
 * Insert a new item directly after a certain item in the list
 * @param list List
 * @param item Item
 * @return A pointer to the newly inserted item
 */
void* list_insert_after(List* list, const void* item);

/**
 * Insert a new item directly before a certain item in the list
 * @param list List
 * @param item Item
 * @return A pointer to the newly inserted item
 */
void* list_insert_before(List* list, const void* item);

/**
 * Remove a certain item from the list
 * @param list List
 * @param item Item
 */
void list_delete_item(List* list, const void* item);

/**
 * Delete the list including all its contents
 * @param list List
 */
void list_delete(List* list);

#endif //GENERIC_LIST_LIST_H
