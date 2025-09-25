//
// Created by Khey_Saliga on 24/09/2025.
//

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void stack_init(Stack *stack) {
    stack->top = NULL;
    stack->count = 0;
}

void stack_definit(Stack *stack) {
    while (!stack_is_empty(stack)) {
        stack_pop(stack);
    }
}


// Peek at top element
int stack_peek(Stack *stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "Stack is empty! No top element.\n");
        return -1;
    }
    return stack->top->data;
}

int stack_pop(Stack *stack) {
    if (stack_is_empty(stack)) {
        fprintf(stderr, "Stack underflow! Nothing to pop.\n");
        return -1;
    }

    StackNode *temp = stack->top;
    int value = temp->data;

    stack->top = stack->top->next;
    free(temp);
    stack->count--;

    return value;
}

void stack_push(Stack *stack, int data) {
    StackNode *node = malloc(sizeof(StackNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->count++;
}

int stack_is_empty(Stack *stack) {
    return stack->count == 0;
}