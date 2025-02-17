#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) return NULL;
    stack->head = NULL;
    stack->size = 0;
    return stack;
}

int getSize(Stack* stack) {
    return stack ? stack->size : 0;
}

bool isEmpty(Stack* stack) {
    return stack->head == NULL;
}

void push(Stack* stack, void* data) {
    if (!stack) return;

    Node* new_node = createNode(data);
    if (!new_node) return;

    new_node->next = stack->head;
    stack->head = new_node;
    stack->size++;
}

void* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: La cola esta vacia\n");
        return NULL;
    }

    Node* temp = stack->head;
    void* data = temp->data;
    stack->head = temp->next;
    free(temp);
    stack->size--;
    return data;
}

void* peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: La cola esta vacia\n");
        return NULL;
    }
    return stack->head->data;
}

void showStack(Stack* stack, void (*print_func)(void*)) {
    if (isEmpty(stack)) {
        printf("La cola esta vacia.\n");
        return;
    }

    Node* current = stack->head;
    while (current) {
        print_func(current->data);
        printf(" -> ");
        current = current->next;
    }
    printf("NULL\n");
}

void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}