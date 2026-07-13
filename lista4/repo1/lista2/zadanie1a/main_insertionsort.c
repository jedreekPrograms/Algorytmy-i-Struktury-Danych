#include <stdio.h>
#include "../helpfunctions/helpfunctions.h"
#include "insertionsort.h"

int main() {
    int n;
    scanf("%d", &n);

    int tab[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &tab[i]);
    }

    int swaps = 0;
    int comparisons = 0;

    insertionsort(tab, 0, n - 1, &swaps, &comparisons);

    // ===== ZADANIE 1 (DEBUG) =====
    // printf("Comparisons: %d\n", comparisons);
    // printf("Swaps: %d\n", swaps);

    // ===== ZADANIE 2 (DANE DO PLIKU) =====
    printf("%d %d %d\n", n, comparisons, swaps);

    return 0;
}