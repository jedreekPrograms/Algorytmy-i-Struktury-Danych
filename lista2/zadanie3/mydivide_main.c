#include <stdio.h>
#include "mydivide.h"

int main() {
    int n;

    scanf("%d", &n);

    int tab[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &tab[i]);
    }

    int comparisons = 0;
    int swaps = 0;

    mydivide(tab, 0, n - 1, &swaps, &comparisons);

    printf("%d %d %d\n", n, comparisons, swaps);

    return 0;
}