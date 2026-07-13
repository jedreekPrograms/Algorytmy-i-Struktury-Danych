#include <iostream>
#include <vector>
#include "Select.h"
#include <algorithm>
#include <chrono>

using namespace std;

int main() {
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<int> tab(n);

    for (int i = 0; i < n; i++) {
        cin >> tab[i];
    }

    int swaps = 0;
    int comparisons = 0;

    auto start = chrono::high_resolution_clock::now();

    int wynik = Select(tab.data(), 0, n - 1, n / 2 + 1, k, &swaps, &comparisons);

    auto end = chrono::high_resolution_clock::now();

    long long time = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << n << " " << k << " " << swaps << " " << comparisons << " " << time << "\n";

    return 0;
}
