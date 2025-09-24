
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void linked_list_append(LinkedList *self, void *data) {
    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    node->data = data;
    node->next = NULL;

    if (self->head == NULL) {
        // List is empty
        self->head = node;
    } else {
        LinkedListNode *last = self->head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = node;
    }

    self->size += 1;
}

void linked_list_insert(LinkedList *self, size_t index, void *data) {
    if (index > self->size) return; // out of bounds

    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    node->data = data;

    if (index == 0) {
        // insert at head
        node->next = self->head;
        self->head = node;
    } else {
        LinkedListNode *prev = self->head;
        for (size_t i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        node->next = prev->next;
        prev->next = node;
    }
    self->size += 1;
}

void linked_list_remove(LinkedList *self, size_t index) {
    if (index >= self->size || self->head == NULL) return; // invalid

    LinkedListNode *temp;
    if (index == 0) {
        // remove head
        temp = self->head;
        self->head = self->head->next;
    } else {
        LinkedListNode *prev = self->head;
        for (size_t i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        temp = prev->next;
        prev->next = temp->next;
    }
    free(temp);
    self->size -= 1;
}

void linked_list_clear(LinkedList *self) {
    LinkedListNode *last = self->head;
    while (last->next != NULL) {
        LinkedListNode *current = last;
        last = last->next;
        free(current);
    }
    self->head = NULL;
    self->size = 0;
}

void *linked_list_get(LinkedList *self, size_t index) {
    if (index >= self->size) return NULL; // out of bounds

    LinkedListNode *current = self->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}
