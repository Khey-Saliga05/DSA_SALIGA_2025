//
// Created by ACLC on 9/17/2025.
//

#ifndef KHEY_LINKED_LIST_H
#define KHEY_LINKED_LIST_H


#include <stdio.h>

typedef struct LinkListNode {
    struct LinkListNode *next;
    void *data;
} LinkedListNode;

typedef struct {
    LinkedListNode *head;
    //LinkedListNode *tail;
    size_t size;
} LinkedList;

void linked_list_append(LinkedList *self, void *data);

void linked_list_insert(LinkedList *self, size_t index, void *data);

void linked_list_remove(LinkedList *self, size_t index);

void linked_list_clear(LinkedList *self);

void *linked_list_get(LinkedList *self, size_t index);

#endif //KHEY_LINKED_LIST_H
