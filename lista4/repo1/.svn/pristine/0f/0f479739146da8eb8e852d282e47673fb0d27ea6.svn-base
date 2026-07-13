#include "../helpfunctions/helpfunctions.h"
#include <iostream>
using namespace std;

void my_swap(int *i, int *j, int *swaps) {
    (*swaps)++;
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

int less_than(int a, int b, int *comp) {
    (*comp)++;
    return a < b;
}

int greater_than(int a, int b, int *comp) {
    (*comp)++;
    return a > b;
}

int leq(int a, int b, int *comp) {
    (*comp)++;
    return a <= b;
}

int geq(int a, int b, int *comp) {
    (*comp)++;
    return a >= b;
}

int eq(int a, int b, int *comp) {
    (*comp)++;
    return a == b;
}

void print(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
}

void insertionsort(int A[], int l, int r, int *comparisons) {
    for (int i = l + 1; i <= r; i++) {
        int key = A[i];
        int j = i - 1;

        while (j >= l && greater_than(A[j], key, comparisons)) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void print_d(double A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
}