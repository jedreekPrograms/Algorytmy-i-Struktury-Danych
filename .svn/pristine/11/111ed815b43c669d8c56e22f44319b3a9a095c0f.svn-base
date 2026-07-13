

#define SIZE 10000
#define SEARCHES 1000
#define MAX_VALUE 100000
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cyclic_list.h"

int main() {

    srand(time(NULL));

    CyclicList l1, l2;
    initList(&l1);
    initList(&l2);

    for (int i = 0; i < 10; i++) {
        insert(&l1, rand() % 90 + 10);
        insert(&l2, rand() % 90 + 10);
    }

    printf("Lista 1:\n");
    printList(&l1);

    printf("Lista 2:\n");
    printList(&l2);

    printf("Po merge:\n");
    merge(&l1, &l2);
    printList(&l1);

    CyclicList L;
    initList(&L);

    int T[SIZE];

    for (int i = 0; i < SIZE; i++) {
        T[i] = rand() % (MAX_VALUE + 1);
        insert(&L, T[i]);
    }

    long totalCost1 = 0;
    long totalCost2 = 0;

    for (int i = 0; i < SEARCHES; i++) {
        int index = rand() % (SIZE);
        int comparisons = 0;
        search(&L, T[index], &comparisons);
        totalCost1 += comparisons;
    }

    for (int i = 0; i < SEARCHES; i++) {
        int value = rand() % (MAX_VALUE + 1);
        int comparisons = 0;
        search(&L, value, &comparisons);
        totalCost2 += comparisons;
    }

    printf("\n=== WYNIKI ===\n");
    printf("Sredni koszt (element z listy): %.2f\n",
           (double)totalCost1 / SEARCHES);

    printf("Sredni koszt (losowa liczba): %.2f\n",
           (double)totalCost2 / SEARCHES);

    freeList(&l1);
    freeList(&l2);
    freeList(&L);

    return 0;


}
