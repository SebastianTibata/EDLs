#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "node.h"

typedef struct {
    Node* head;
    Node* tail;
    int size;
} Queue;

Queue* createQueue();
int queue_getSize(Queue* queue);
bool queue_isEmpty(Queue* queue);
void queue_push(Queue* queue, void* data);
void* queue_pop(Queue* queue);
void* queue_peek(Queue* queue);
void showQueue(Queue* queue, void (*print_func)(void*));
void freeQueue(Queue* queue);

#endif