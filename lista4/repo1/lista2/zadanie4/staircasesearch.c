#include "staircasesearch.h"
#include "binarysearch.h"

int staircasesearch(int m, int n, int tab[m][n], int x, int *comparisons) {

    int i = 0;
    int j = n - 1;

    while (i < m && j >= 0) {
        int cmp = compare(tab[i][j], x, comparisons);

        if (cmp == 0) return 1;
        else if (cmp > 0) j--;
        else i++;
    }

    return 0;
}