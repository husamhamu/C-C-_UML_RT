#include <stdlib.h>

#include "list.h"

struct List {
    size_t item_size;
    struct ListItemHeader *first, *last;
};

struct ListItemHeader {
    struct ListItemHeader *next, *previous;
};

List* list_init(size_t item_size) {
    struct List* list = malloc(sizeof(List));
    list->item_size = item_size;
    list->first = NULL;
    list->last = NULL;
    return list;
}

void* list_first(const List* list) {
    return list->first ? (list->first + 1) : NULL;
}

void* list_last(const List* list) {
    return list->last ? (list->last + 1) : NULL;
}

void* list_next(const void* item) {
    const struct ListItemHeader* header =
        item - sizeof(struct ListItemHeader);
    return header->next ? (header->next + 1) : NULL;
}

void* list_previous(const void* item) {
    const struct ListItemHeader* header =
        item - sizeof(struct ListItemHeader);
    return header->previous ? (header->previous + 1) : NULL;
}

void* list_prepend(List* list) {
    struct ListItemHeader* new_item =
        malloc(sizeof(struct ListItemHeader) + list->item_size);
    new_item->previous = NULL;
    new_item->next = NULL;
    if (list->first) {
        new_item->next = list->first;
        list->first->previous = new_item;
    }
    list->first = new_item;
    if (!list->last) {
        list->last = new_item;
    }
    return new_item + 1;
}

void* list_append(List* list) {
    struct ListItemHeader* new_item =
        malloc(sizeof(struct ListItemHeader) + list->item_size);
    new_item->previous = NULL;
    new_item->next = NULL;
    if (list->last) {
        new_item->previous = list->last;
        list->last->next = new_item;
    }
    list->last = new_item;
    if (!list->first) {
        list->first = new_item;
    }
    return new_item + 1;
}

void* list_insert_after(List* list, const void* item) {
    struct ListItemHeader* header =
        (void*)item - sizeof(struct ListItemHeader);
    struct ListItemHeader* new_item =
        malloc(sizeof(struct ListItemHeader) + list->item_size);
    new_item->previous = header;
    new_item->next = header->next;
    header->next = new_item;
    if (new_item->next) {
        new_item->next->previous = new_item;
    }
    else {
        list->last = new_item;
    }
    return new_item + 1;
}

void* list_insert_before(List* list, const void* item) {
    struct ListItemHeader* header =
        (void*)item - sizeof(struct ListItemHeader);
    struct ListItemHeader* new_item =
        malloc(sizeof(struct ListItemHeader) + list->item_size);
    new_item->previous = header->previous;
    new_item->next = header;
    header->previous = new_item;
    if (new_item->previous) {
        new_item->previous->next = new_item;
    }
    else {
        list->first = new_item;
    }
    return new_item + 1;
}

void list_delete_item(List* list, const void* item) {
    struct ListItemHeader* header =
        (void*)item - sizeof(struct ListItemHeader);
    if (header->previous) {
        header->previous->next = header->next;
    }
    else {
        list->first = header->next;
    }
    if (header->next) {
        header->next->previous = header->previous;
    }
    else {
        list->last = header->previous;
    }
    free(header);
}

void list_delete(List* list) {
    void* ptr;
    while ((ptr = list_first(list)) != NULL) {
        list_delete_item(list, ptr);
    }
    free(list);
}
