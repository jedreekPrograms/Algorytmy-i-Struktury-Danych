#include "../helpfunctions/helpfunctions.h"

void insertionsort(int tab[], int p, int q, int *swaps, int *comparisons) {

    for (int j = p + 1; j <= q; j++) {

        int key = tab[j];
        int i = j - 1;

        while (i >= p && compare(key, tab[i], comparisons)) {
            tab[i + 1] = tab[i];
            i--;
        }

        tab[i + 1] = key;
        //(*swaps)++;

        // if (q - p + 1 < 40) {
        //     print(q - p + 1, &tab[p]);
        // }
    }
}