//
// Created by Khey_Saliga on 24/09/2025.
//

#ifndef DSA_SALIGA_STACK_H
#define DSA_SALIGA_STACK_H

#endif //DSA_SALIGA_STACK_H

#include <stddef.h>

typedef struct StackNode {
    struct StackNode *next;
    int data;
} StackNode;

typedef struct {
    StackNode *top;
    size_t count;
} Stack;

void stack_init(Stack *stack);
void stack_definit(Stack *stack);
int stack_peek(Stack *stack);
int stack_pop(Stack *stack);
void stack_push(Stack *stack, int data);