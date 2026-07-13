#include "doubly_cyclic_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void initList(ListNode* l) {
    l->size = 0;
    l->head = NULL;
}
void insert(ListNode* l, int value) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Błąd pamięci");
        exit(1);
    }

    newNode->data = value;

    if (l->head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        l->head = newNode;
    } else {
        Node* first = l->head->next;

        newNode->next = first;
        newNode->prev = l->head;

        first->prev = newNode;
        l->head->next = newNode;
    }
    l->size++;
}
void merge(ListNode* l1, ListNode* l2) {

    if (l2->head == NULL) return;

    if (l1->head == NULL) {
        l1->head = l2->head;
        l1->size = l2->size;
    } else {

        Node* temp1 = l1->head->next;
        Node* temp2 = l2->head->next;

        l1->head->next = temp2;
        temp2->prev = l1->head;

        l2->head->next = temp1;
        temp1->prev = l2->head;

        l1->size += l2->size;
    }

    l2->head = NULL;
    l2->size = 0;
}
int search(ListNode* l, int value, int* comparisons) {
    if (l->head == NULL) {
        *comparisons = 0;
        return 0;
    }

    int direction = rand() % 2;

    Node* current = l->head;
    int count = 0;

    do {
        count++;
        if (current->data == value) {
            *comparisons = count;
            return 1;
        }

        if (direction == 0) {
            current = current->next;
        } else {
            current = current->prev;
        }
    } while (current != l->head);

    *comparisons = count;
    return 0;
}
void printList(ListNode* l) {
    if (l->head == NULL) {
        printf("Lista pusta");
        return;
    }

    Node* current = l->head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != l->head);
    printf("\n");
}
void freeList(ListNode* l) {
    if (l->head == NULL) return;

    Node* current = l->head->next;
    Node* temp;

    while (current != l->head) {
        temp = current;
        current = current->next;
        free(temp);
    }

    free(l->head);
    l->head = NULL;
    l->size = 0;
}