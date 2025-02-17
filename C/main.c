#include <stdio.h>
#include "stack.h"
#include "queue.h"

void printInt(void* data) {
    printf("%d", *(int*)data);
}

int main() {
    Stack* stack = createStack();
    Queue* queue = createQueue();

    int a = 1, b = 2, c = 3;
    int d = 4, e = 5, f = 6;

    push(stack, &a);
    push(stack, &b);
    push(stack, &c);

    queue_push(queue, &d);
    queue_push(queue, &e);
    queue_push(queue, &f);

    printf("Stack: ");
    showStack(stack, printInt);
    printf("\nQueue: ");
    showQueue(queue, printInt);

    return 0;
}
