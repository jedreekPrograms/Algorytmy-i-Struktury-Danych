#include <stdio.h>
#include "../helpfunctions/helpfunctions.h"
#include "quicksort.h"

int main() {
    int n;
    scanf("%d", &n);

    int tab[n];
    int original[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &tab[i]);
        original[i] = tab[i];
    }

    if (n < 40) {
        printf("Wejscie:\n");
        print(n, tab);
    }

    int swaps = 0;
    int comparisons = 0;

    quicksort(tab, 0, n - 1, &swaps, &comparisons);

    if (n < 40) {
        printf("Wejscie (ponownie):\n");
        print(n, original);

        printf("Wyjscie:\n");
        print(n, tab);
    }

    if (!is_sorted(n, tab)) {
        printf("Blad sortowania!\n");
    }

    printf("Comparisons: %d\n", comparisons);
    printf("Swaps: %d\n", swaps);

    return 0;
}