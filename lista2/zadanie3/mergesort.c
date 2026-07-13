#include "../helpfunctions/helpfunctions.h"

void merge(int *tab, int p, int m, int q, int *swaps, int *comparisons) {
    int A[q - p + 1];
    int k = 0;

    int i = p;
    int j = m + 1;

    while (i <= m && j <= q) {
        if (compare(tab[i], tab[j], comparisons) < 0) {
            A[k++] = tab[i++];
            (*swaps)++;
        } else {
            A[k++] = tab[j++];
            (*swaps)++;
        }
    }

    while (i <= m) {
        A[k++] = tab[i++];
        (*swaps)++;
    }

    while (j <= q) {
        A[k++] = tab[j++];
        (*swaps)++;
    }

    for (int i = 0; i < (q - p + 1); i++) {
        tab[p + i] = A[i];
        (*swaps)++;
    }
}

void mergesort(int tab[], int p, int q, int *swaps, int *comparisons) {
    if (p >= q) return;

    int m = p + (q - p) / 2;

    mergesort(tab, p, m, swaps, comparisons);
    mergesort(tab, m + 1, q, swaps, comparisons);

    merge(tab, p, m, q, swaps, comparisons);
}