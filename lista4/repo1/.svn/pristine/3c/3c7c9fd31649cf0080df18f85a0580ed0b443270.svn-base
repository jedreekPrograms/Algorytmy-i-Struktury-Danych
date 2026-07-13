#include <stdbool.h>
#include "../helpfunctions/helpfunctions.h"

int HoarePartition(int *tab, int p, int q, int *swaps, int *comparisons) {
    int pivot = tab[p];

    int i = p - 1;
    int j = q + 1;

    while (true) {

        do {
            i++;
        } while (compare(tab[i], pivot, comparisons));

        do {
            j--;
        } while (compare(pivot, tab[j], comparisons));

        if (i >= j) return j;

        swap(&tab[i], &tab[j], swaps);
    }
}

void quicksort(int tab[], int p, int q, int *swaps, int *comparisons) {
    if (p < q) {
        int r = HoarePartition(tab, p, q, swaps, comparisons);

        // if (q - p + 1 < 40) {
        //     print(q - p + 1, &tab[p]);
        // }

        quicksort(tab, p, r, swaps, comparisons);
        quicksort(tab, r + 1, q, swaps, comparisons);
    }
}