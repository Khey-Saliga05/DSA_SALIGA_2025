//
// Created by Khey_Saliga on 24/09/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void queue_init(Queue *queue) {
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

void queue_definit(Queue *queue) {
    while (!queue_is_empty(queue)) {
        queue_dequeue(queue);
    }
}

void queue_enqueue(Queue *queue, int data) {
    QueueNode *node = malloc(sizeof(QueueNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;

    if (queue->tail) {
        queue->tail->next = node;
    } else {
        queue->head = node;
    }
    queue->tail = node;
    queue->size++;
}

int queue_dequeue(Queue *queue) {
    if (queue_is_empty(queue)) {
        fprintf(stderr, "Queue underflow! Nothing to dequeue.\n");
        return -1;
    }

    QueueNode *temp = queue->head;
    int value = temp->data;

    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    free(temp);
    queue->size--;
    return value;
}

int queue_peek_head(Queue *queue) {
    if (queue_is_empty(queue)) {
        fprintf(stderr, "Queue is empty! No head element.\n");
        return -1;
    }
    return queue->head->data;
}

int queue_peek_tail(Queue *queue) {
    if (queue_is_empty(queue)) {
        fprintf(stderr, "Queue is empty! No tail element.\n");
        return -1;
    }
    return queue->tail->data;
}

int queue_is_empty(Queue *queue) {
    return queue->size == 0;
}
