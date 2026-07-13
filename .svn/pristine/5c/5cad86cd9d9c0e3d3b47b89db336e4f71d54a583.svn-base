#include <iostream>
#include <vector>
#include "MyFind.h"

using namespace std;

int GLOBAL_NUMBER = 0;
int FUNCTION_NUMBER = 0;

int main() {
    int n;
    cin >> n;

    GLOBAL_NUMBER = (n <= 30);  // 🔥 spójnie z binary

    vector<double> A(n);
    for (double &x : A) cin >> x;

    double k;
    cin >> k;

    cin >> FUNCTION_NUMBER;

    int fallback = 0;
    int comparisons = 0;

    int idx = MyFind(A.data(), n, k, fallback, comparisons);

    if (GLOBAL_NUMBER) {
        cout << "A:\n";
        for (double x : A) cout << x << " ";
        cout << "\n";

        cout << "k = " << k << "\n";
        cout << "indeks = " << idx << "\n";
        cout << (idx != -1 ? "TAK\n" : "NIE\n");
    }

    cout << n << " " << k << " " << comparisons << " " << (idx != -1) << "\n";
}