//
// Created by Khey_Saliga on 24/09/2025.
//

#ifndef DSA_SALIGA_QUEUE_H
#define DSA_SALIGA_QUEUE_H

#endif //DSA_SALIGA_QUEUE_H

#include <stddef.h>

typedef struct QueueNode {
    struct Queue *new;
    int data;
} QueueNode;

typedef struct {
    QueueNode *head;
    QueueNode *tail;
    size_t size;
} Queue;

Queue queue_init(Queue *queue) ;
Queue queue_definit(Queue *queue) ;
void queue_enqueue(Queue *queue, int data) ;
int queue_dequeue(Queue *queue) ;
int queue_peek_head(Queue *queue);
int queue_peek_tail(Queue *queue) ;