// Select.cpp

#include <vector>
#include <algorithm>
#include <iostream>

#include "../helpfunctions/helpfunctions.h"

extern int GLOBAL_NUMBER;

using namespace std;

int find_median(int A[], int l, int r, int *comparisons) {

    int temp[5];

    int size = r - l + 1;

    for (int i = 0; i < size; i++) {
        temp[i] = A[l + i];
    }

    insertionsort(temp, 0, size - 1, comparisons);

    return temp[size / 2];
}
void Partition_pivot(
    int A[],
    int l,
    int r,
    int pivot,
    int *swaps,
    int *comparisons,
    int &left_end,
    int &right_start
) {

    int pivotIndex = l;

    while (pivotIndex <= r && !eq(A[pivotIndex], pivot, comparisons)) {
        pivotIndex++;
    }

    if (pivotIndex > r) {
        cout << "ERROR: pivot not found\n";
        exit(1);
    }

    my_swap(&A[l], &A[pivotIndex], swaps);

    int lt = l;
    int gt = r;
    int i = l;

    while (i <= gt) {

        if (less_than(A[i], pivot, comparisons)) {
            my_swap(&A[i], &A[lt], swaps);
            lt++;
            i++;
        }
        else if (less_than(pivot, A[i], comparisons)) {
            my_swap(&A[i], &A[gt], swaps);
            gt--;
        }
        else {
            i++;
        }
    }

    left_end = lt - 1;
    right_start = gt + 1;

    if (GLOBAL_NUMBER == 1) {
        cout << "Pivot: " << pivot << "\n";
        cout << "Tablica: ";
        print(A + l, r - l + 1);
        cout << "\n";
    }
}

int Select(
    int A[],
    int l,
    int r,
    int k,
    int *swaps,
    int *comparisons
) {

    if (GLOBAL_NUMBER == 1) {
        cout << "Select [" << l << "," << r << "] k=" << k << "\n";
        cout << "Tablica: ";
        print(A + l, r - l + 1);
    }

    int n = r - l + 1;

    // WARUNEK BAZOWY
    if (n <= 5) {
        insertionsort(A, l, r, comparisons);
        return A[l + k - 1];
    }

    int groups = (n + 4) / 5;

    vector<int> medians(groups);

    int idx = 0;

    for (int i = l; i <= r; i += 5) {

        int end = min(i + 4, r);

        medians[idx++] = find_median(
            A,
            i,
            end,
            comparisons
        );
    }

    // MEDIANA MEDIAN
    int pivot = Select(
        medians.data(),
        0,
        groups - 1,
        (groups + 1) / 2,
        swaps,
        comparisons
    );

    int left_end;
    int right_start;

    Partition_pivot(
        A,
        l,
        r,
        pivot,
        swaps,
        comparisons,
        left_end,
        right_start
    );

    int left_size = left_end - l + 1;

    int middle_size = right_start - left_end - 1;

    if (k <= left_size) {
        return Select(
            A,
            l,
            left_end,
            k,
            swaps,
            comparisons
        );
    }

    if (k <= left_size + middle_size) {
        return pivot;
    }

    return Select(
        A,
        right_start,
        r,
        k - left_size - middle_size,
        swaps,
        comparisons
    );
}
