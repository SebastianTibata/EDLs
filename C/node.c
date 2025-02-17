#include <stdlib.h>
#include "node.h"

Node* createNode(void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void* getData(Node* node) {
    return node ? node->data : NULL;
}

void setData(Node* node, void* data) {
    if (node) node->data = data;
}

Node* getNext(Node* node) {
    return node ? node->next : NULL;
}

void setNext(Node* node, Node* next) {
    if (node) node->next = next;
}

void freeNode(Node* node) {
    if (node) free(node);
}
