
#ifndef LABY1_CYCLIC_LIST_TWO_WAY_H
#define LABY1_CYCLIC_LIST_TWO_WAY_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct ListNode {
    int size;
    struct Node* head;
} ListNode;

void initList(ListNode* l);
void insert(ListNode* l, int value);
void merge(ListNode* l1, ListNode* l2);
int search(ListNode* l, int value, int* comparisons);
void printList(ListNode* l);
void freeList(ListNode* l);

#endif //LABY1_CYCLIC_LIST_TWO_WAY_H