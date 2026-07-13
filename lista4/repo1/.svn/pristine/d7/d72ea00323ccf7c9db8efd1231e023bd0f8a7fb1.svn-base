// RandomizedSelect_main.cpp

#include <iostream>
#include <vector>

#include "RandomizedSelect.h"
#include "../helpfunctions/helpfunctions.h"

using namespace std;

int GLOBAL_NUMBER = 0;

int main() {

    int n;
    cin >> n;

    int k;
    cin >> k;

    int number;
    cin >> number;

    vector<int> tab(n);

    for (int i = 0; i < n; i++) {
        cin >> tab[i];
    }

    vector<int> original = tab;

    int swaps = 0;
    int comparisons = 0;

    if (number == 1) {
        GLOBAL_NUMBER = 1;
    }

    if (number == 1 && n <= 30) {
        cout << "Poczatkowa tablica:\n";
        print(tab.data(), n);
    }

    int result = RandomizedSelect(
        tab.data(),
        0,
        n - 1,
        k,
        &swaps,
        &comparisons
    );

    if (number == 1 && n <= 30) {

        cout << "Koncowa tablica:\n";
        print(tab.data(), n);

        cout << "Znaleziona statystyka pozycyjna: "
             << result << "\n";

        cout << "Poczatkowa tablica:\n";
        print(original.data(), n);

        cout << "Posortowana tablica:\n";

        int tmp = 0;

        insertionsort(
            original.data(),
            0,
            n - 1,
            &tmp
        );

        print(original.data(), n);
    }

    // format pod wykresy
    cout << n
         << " "
         << k
         << " "
         << swaps
         << " "
         << comparisons
         << "\n";

    return 0;
}