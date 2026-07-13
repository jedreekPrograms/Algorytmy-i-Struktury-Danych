#include <stdio.h>
#include <stdlib.h>
#include "cyclic_list.h"

void initList(CyclicList* l) {
    l->size = 0;
    l->head = NULL;
}
void insert(CyclicList* l, int value) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("Blad alokacji pamieci");
        exit(1);
    }

    newNode->value = value;

    if (l->head == NULL) {
        newNode->next = newNode;
        l->head = newNode;
    } else {
        newNode->next = l->head->next;
        l->head->next = newNode;
    }

    l->size++;
}
void merge(CyclicList* l1, CyclicList* l2) {
    if (l2->head == NULL) return;

    if (l1->head == NULL) {
        l1->head = l2->head;
        l1->size = l2->size;
        return;
    }

    ListNode* temp = l1->head->next;
    l1->head->next = l2->head->next;
    l2->head->next = temp;

    l1->size += l2->size;

    l2->head = NULL;
    l2->size = 0;
}
int search(CyclicList* l, int value, int *comparisons) {
    if (l->head == NULL) {
        *comparisons = 0;
        return 0;
    }

    ListNode* current = l->head;
    int count = 0;

    do {
        count++;
        if (current->value == value) {
            *comparisons = count;
            return 1;
        }
        current = current->next;
    } while (current != l->head);

    *comparisons = count;
    return 0;
}
void printList(CyclicList* l){
    if (l->head == NULL) {
        printf("Lista pusta\n");
        return;
    }
    ListNode* current = l->head;

    do {
        printf("%d ", current->value);
        current = current->next;
    } while (current != l->head);

    printf("\n");
}
void freeList(CyclicList* l) {

    if (l->head == NULL) return;

    ListNode* current = l->head->next;
    ListNode* temp;

    while (current != l->head) {
        temp = current;
        current = current->next;
        free(temp);
    }

    free(l->head);
    l->head = NULL;
    l->size = 0;
}