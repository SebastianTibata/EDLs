#ifndef NODE_H
#define NODE_H

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

Node* createNode(void* data);
void* getData(Node* node);
void setData(Node* node, void* data);
Node* getNext(Node* node);
void setNext(Node* node, Node* next);
void freeNode(Node* node);

#endif