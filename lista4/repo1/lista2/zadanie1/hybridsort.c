#include "hybridsort.h"
#include "insertionsort.h"
#include "quicksort.h"

int K = 15;

void hybridsort(int p, int q, int tab[], int *swaps, int *comparisons) {
    if (p < q) {
        if (q - p + 1 <= K) {
            insertionsort(tab, p, q, swaps, comparisons);
        } else {
            int r = HoarePartition(tab, p, q, swaps, comparisons);

            hybridsort(p, r, tab, swaps, comparisons);
            hybridsort(r + 1, q, tab, swaps, comparisons);
        }
    }
}