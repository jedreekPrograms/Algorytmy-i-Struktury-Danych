#ifndef LABY1_CYCLICLIST_H
#define LABY1_CYCLICLIST_H

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct {
    int size;
    ListNode* head;
} CyclicList;

void initList(CyclicList* l);
void insert(CyclicList* l, int value);
void merge(CyclicList* l1, CyclicList* l2);
int search(CyclicList* l, int value, int *comparisons);
void printList(CyclicList* l);
void freeList(CyclicList* l);

#endif