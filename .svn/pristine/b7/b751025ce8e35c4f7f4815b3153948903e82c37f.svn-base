#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q);
int isEmptyQueue(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);

#endif