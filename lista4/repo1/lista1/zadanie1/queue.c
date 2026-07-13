#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isQueueEmpty(Queue* q) {
    return (q->front == NULL);
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Blad alokacji pamieci!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Blad: proba pobrania pustej kolejki!\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}