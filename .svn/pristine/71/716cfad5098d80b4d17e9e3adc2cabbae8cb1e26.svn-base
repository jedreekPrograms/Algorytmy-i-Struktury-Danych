#include "binarysearch.h"

int binarysearch_row(int row, int p, int q, int m, int n, int tab[m][n],
                     int x, int *comparisons) {

    while (p <= q) {
        int mid = p + (q - p) / 2;

        int cmp = compare(tab[row][mid], x, comparisons);

        if (cmp == 0) return 1;
        else if (cmp > 0) q = mid - 1;
        else p = mid + 1;
    }

    return 0;
}

int binarysearch_matrix(int m, int n, int tab[m][n], int x, int *comparisons) {

    for (int i = 0; i < m; i++) {

        // szybkie odrzucenie (NIE LICZYMY DO comparisons)
        if (x < tab[i][0]) return 0;
        if (x > tab[i][n - 1]) continue;

        if (binarysearch_row(i, 0, n - 1, m, n, tab, x, comparisons))
            return 1;
    }

    return 0;
}

int compare(int a, int b, int *comparisons) {
    (*comparisons)++;

    if (a == b) return 0;
    return (a < b) ? -1 : 1;
}