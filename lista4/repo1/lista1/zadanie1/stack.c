#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(Stack* s) {
    s->top = NULL;
}
int isEmptyStack(Stack* s) {
    return (s->top == NULL);
}
void push(Stack* s, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Blad alokacji pamieci");
        exit(1);
    }

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}
int pop(Stack* s) {
    if (isEmptyStack(s)) {
        printf("Blad: Proba pobrania z pustego stosu");
        exit(1);
    }

    Node* temp = s->top;
    int value = temp->data;

    s->top = s->top->next;
    free(temp);

    return value;
}