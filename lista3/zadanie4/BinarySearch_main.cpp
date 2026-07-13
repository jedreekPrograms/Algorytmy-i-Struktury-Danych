#include <iostream>
#include <vector>
#include "BinarySearch.h"

using namespace std;

int GLOBAL_NUMBER = 0;

int main() {
    int n;
    cin >> n;

    GLOBAL_NUMBER = (n <= 30);  // 🔥 zgodnie z wymaganiem prowadzącego

    vector<double> A(n);
    for (double &x : A) cin >> x;

    double k;
    cin >> k;

    int functionNumber;
    cin >> functionNumber; // ignorowane

    int comparisons = 0;
    int idx = BinarySearch(A.data(), 0, n - 1, k, comparisons);

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