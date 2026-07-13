// RandomizedSelect.cpp

#include <cstdlib>
#include <iostream>

#include "../helpfunctions/helpfunctions.h"

extern int GLOBAL_NUMBER;

using namespace std;

void PartitionRandomized(
    int A[],
    int l,
    int r,
    int *swaps,
    int *comparisons,
    int &left_end,
    int &right_start
) {

    int pivotIndex = l + rand() % (r - l + 1);

    int pivot = A[pivotIndex];

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

int RandomizedSelect(
    int A[],
    int l,
    int r,
    int k,
    int *swaps,
    int *comparisons
) {

    if (GLOBAL_NUMBER == 1) {
        cout << "RandomizedSelect ["
             << l
             << ","
             << r
             << "] k="
             << k
             << "\n";

        cout << "Tablica: ";
        print(A + l, r - l + 1);
    }

    if (l == r) {
        return A[l];
    }

    int left_end;
    int right_start;

    PartitionRandomized(
        A,
        l,
        r,
        swaps,
        comparisons,
        left_end,
        right_start
    );

    int left_size = left_end - l + 1;

    int middle_size = right_start - left_end - 1;

    if (k <= left_size) {
        return RandomizedSelect(
            A,
            l,
            left_end,
            k,
            swaps,
            comparisons
        );
    }

    if (k <= left_size + middle_size) {
        return A[left_end + 1];
    }

    return RandomizedSelect(
        A,
        right_start,
        r,
        k - left_size - middle_size,
        swaps,
        comparisons
    );
}