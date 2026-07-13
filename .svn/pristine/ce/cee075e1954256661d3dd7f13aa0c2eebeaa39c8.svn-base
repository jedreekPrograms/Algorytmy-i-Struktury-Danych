#include "hybridsearch.h"
#include <math.h>

#include "binarysearch.h"
#include "staircasesearch.h"

int hybrid_search(int m, int n, int tab[m][n], int x, int *comparisons) {

    double logn = log2((double)n);

    // zabezpieczenie (gdy n=1)
    if (logn < 1.0) logn = 1.0;

    double binary_cost = m * logn;
    double staircase_cost = m + n;

    if (binary_cost <= staircase_cost)
        return binarysearch_matrix(m, n, tab, x, comparisons);
    else
        return staircasesearch(m, n, tab, x, comparisons);
}