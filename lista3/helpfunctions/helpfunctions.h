#ifndef LABY3CPP_HELPFUNCTIONS_H
#define LABY3CPP_HELPFUNCTIONS_H

void my_swap(int *i, int *j, int *swaps);

int less_than(int a, int b, int *comp);
int greater_than(int a, int b, int *comp);
int leq(int a, int b, int *comp);
int geq(int a, int b, int *comp);
int eq(int a, int b, int *comp);

void insertionsort(int A[], int l, int r, int *comparisons);
void print(int A[], int n);
void print_d(double A[], int n);

#endif