#include <stdio.h>
#include "staircasesearch.h"

int main() {
    int m, n;

    scanf("%d %d", &m, &n);

    int tab[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &tab[i][j]);
        }
    }

    int x;
    scanf("%d", &x);

    int comparisons = 0;

    int result = staircasesearch(m, n, tab, x, &comparisons);

    printf("%d %d %d %d\n", m, n, comparisons, result);

    return 0;
}