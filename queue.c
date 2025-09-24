//
// Created by Khey_Saliga on 24/09/2025.
//

#include "queue.h"


Queue queue_init(Queue *queue) ;
Queue queue_definit(Queue *queue) ;
void queue_enqueue(Queue *queue, int data) ;
int queue_dequeue(Queue *queue) ;
int queue_peek_head(Queue *queue);
int queue_peek_tail(Queue *queue) ;