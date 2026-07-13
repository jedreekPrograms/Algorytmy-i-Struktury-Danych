#include <vector>
#include "../helpfunctions/helpfunctions.h"
#include <algorithm>

using namespace std;

int find_median(int A[], int l, int r, int *swaps, int *comparisons) {

    int size = r - l + 1;
    vector<int> Copy(size);

    for (int i = 0; i < size; i++) {
        Copy[i] = A[i + l];
    }

    insertionsort(Copy.data(), 0, size - 1, comparisons);

    return Copy[size / 2];

}

void Partition_pivot(int A[], int l, int r, int pivot,
                    int *swaps, int *comparisons,
                    int &left_end, int &right_start) {
    int i = l;

    while (i <= r && !eq(A[i], pivot, comparisons)) i++; // ###

    if (i > r) i = l; // ### zabezpieczenie (nie powinno się zdarzyć)

    my_swap(&A[i], &A[l], swaps);

    int lt = l;
    int gt = r;
    int j = l;

    while (j <= gt) {
        if (less_than(A[j], pivot, comparisons)) {
            my_swap(&A[j], &A[lt], swaps);
            lt++;
            j++;
        }
        else if (less_than(pivot, A[j], comparisons)) {
            my_swap(&A[j], &A[gt], swaps);
            gt--;
        }
        else {
            j++;
        }
    }

    left_end = lt - 1;
    right_start = gt + 1;
}

int Select(int A[], int l, int r, int p, int k, int *swaps, int *comparisons) {

    int n = r - l + 1;

    // ### poprawiony warunek bazowy
    if (n <= k) {

        insertionsort(A, l, r, comparisons);

        return A[l + p - 1];
    }
    int size = (n + k - 1) / k;

    vector<int> M(size);
    int f = 0;

    for (int i = l; i <= r; i += k) {
        int end = min(i + k - 1, r);

        M[f++] = find_median(A, i, end, swaps, comparisons);
    }

    int pivot = Select(M.data(), 0, f - 1, (f + 1) / 2, k, swaps, comparisons);

    int left_end;
    int right_start;

    Partition_pivot(A, l, r, pivot, swaps, comparisons, left_end, right_start);

    int left_size = left_end - l + 1;
    int mid_size = right_start - left_end - 1;

    if (p <= left_size) return Select(A, l, left_end, p, k, swaps, comparisons);
    if (p <= left_size + mid_size) return pivot;
    return Select(A, right_start, r, p - left_size - mid_size, k, swaps, comparisons);
}
