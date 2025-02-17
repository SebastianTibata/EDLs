#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) return NULL;
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

bool queue_isEmpty(Queue* queue) {
    return queue->head == NULL;
}

int queue_getSize(Queue* queue) {
    return queue ? queue->size : 0;
}

void queue_push(Queue* queue, void* data) {
    if (!queue) return;

    Node* newNode = createNode(data);
    if (!newNode) return;

    if (queue_isEmpty(queue)) {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }

    queue->size++;
}

void* queue_pop(Queue* queue) {
    if (queue_isEmpty(queue)) {
        printf("Error: La cola esta vacia\n");
        return NULL;
    }

    Node* temp = queue->head;
    void* data = temp->data;
    queue->head = queue->head->next;

    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    free(temp);
    queue->size--;
    return data;
}

void* queue_peek(Queue* queue) {
    if (queue_isEmpty(queue)) {
        printf("La cola esta vacia\n");
        return NULL;
    }
    return queue->head->data;
}

void showQueue(Queue* queue, void (*print_func)(void*)) {
    if (queue_isEmpty(queue)) {
        printf("La cola esta vacia\n");
        return;
    }

    Node* current = queue->head;
    while (current) {
        print_func(current->data);
        printf(" -> ");
        current = current->next;
    }
    printf("NULL\n");
}

void freeQueue(Queue* queue) {
    while (!queue_isEmpty(queue)) {
        queue_pop(queue);
    }
    free(queue);
}