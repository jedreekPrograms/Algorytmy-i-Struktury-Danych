#include <stdlib.h>
#include "mydivide.h"
#include "mergesort.h"
#include "../helpfunctions/helpfunctions.h"

typedef struct {
    int start;
    int end;
} Run;

int find_runs(int tab[], int p, int q, Run runs[], int *comparisons) {
    int run_count = 0;
    int i = p;

    while (i <= q) {
        int start = i;

        while (i < q && compare(tab[i], tab[i+1], comparisons) <= 0) {
            i++;
        }

        runs[run_count].start = start;
        runs[run_count].end = i;
        run_count++;

        i++;
    }

    return run_count;
}

void merge_runs(int tab[], Run runs[], int left, int right,
                int *swaps, int *comparisons) {

    if (left >= right) return;

    int mid = (left + right) / 2;

    merge_runs(tab, runs, left, mid, swaps, comparisons);
    merge_runs(tab, runs, mid + 1, right, swaps, comparisons);

    merge(tab,
          runs[left].start,
          runs[mid].end,
          runs[right].end,
          swaps,
          comparisons);
}

void mydivide(int tab[], int p, int q, int *swaps, int *comparisons) {

    int n = q - p + 1;
    Run *runs = malloc(sizeof(Run) * n);

    int run_count = find_runs(tab, p, q, runs, comparisons);

    merge_runs(tab, runs, 0, run_count - 1, swaps, comparisons);

    free(runs);
}