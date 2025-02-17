#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include "node.h"

typedef struct {
    Node* head;
    int size;
} Stack;

Stack* createStack();
int getSize(Stack* stack);
bool isEmpty(Stack* stack);
void push(Stack* stack, void* data);
void* pop(Stack* stack);
void* peek(Stack* stack);
void showStack(Stack* stack, void (*print_func)(void*));
void freeStack(Stack* stack);

#endif