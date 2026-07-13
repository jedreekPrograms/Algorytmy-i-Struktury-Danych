#include <stdio.h>
#include "../helpfunctions/helpfunctions.h"
#include "quicksort.h"

int main() {
    int n;
    scanf("%d", &n);

    int tab[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &tab[i]);
    }

    int swaps = 0;
    int comparisons = 0;

    quicksort(tab, 0, n - 1, &swaps, &comparisons);

    // ===== ZADANIE 1 =====
    // printf("Comparisons: %d\n", comparisons);
    // printf("Swaps: %d\n", swaps);

    // ===== ZADANIE 2 =====
    printf("%d %d %d\n", n, comparisons, swaps);

    return 0;
}