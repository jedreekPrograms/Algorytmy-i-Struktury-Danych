#include <stdio.h>
#include "queue.h"
#include "stack.h"

#define N 50

int main() {

    Queue q;
    Stack s;

    initQueue(&q);
    initStack(&s);

    printf("=== Dodawanie elementów ===\n");
    for (int i = 1; i <= N; i++) {
        printf("Dodano: %d\n", i);
        enqueue(&q, i);
        push(&s, i);
    }

    printf("\n=== Kolejka (FIFO) ===\n");
    for (int i = 1; i <= N; i++) {
        printf("Zdjeto: %d\n", dequeue(&q));
    }

    dequeue(&q);

    printf("\n=== Stos (LIFO) ===\n");
    for (int i = 1; i <= N; i++) {
        printf("Zdjeto: %d\n", pop(&s));
    }

    pop(&s);

    return 0;
}