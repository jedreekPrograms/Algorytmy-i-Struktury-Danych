#include <stdio.h>

int compare(int a, int b, int *comparisons) {
    (*comparisons)++;
    return a < b;
}

void swap(int *a, int *b, int *swaps) {
    (*swaps)++;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int is_sorted(int n, int tab[]) {
    for (int i = 1; i < n; i++) {
        if (tab[i] < tab[i - 1]) return 0;
    }
    return 1;
}

void print(int n, int tab[]) {
    for (int i = 0; i < n; i++) {
        printf("%02d ", tab[i]);
    }
    printf("\n");
}