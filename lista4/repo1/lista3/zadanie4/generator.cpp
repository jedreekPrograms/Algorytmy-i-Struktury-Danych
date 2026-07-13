#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using namespace std;


// ======================================================
// FUNCTIONS
// ======================================================

static inline double f1(int i) {
    return pow(log2(i + 1.0), 3.0);
}

static inline double f2(int i) {
    return sqrt((double)i)
           + log2(i + 1.0);
}


// ======================================================
// MAIN
// ======================================================

int main(int argc, char *argv[]) {

    if (argc != 3) {
        return 1;
    }

    int n = stoi(argv[1]);

    int function_number = stoi(argv[2]);

    mt19937_64 rng(random_device{}());

    double delta =
        (function_number == 1)
        ? 10.0
        : 50.0;

    uniform_real_distribution<double>
        dist(0.0, delta);

    vector<double> A(n);


    // ======================================================
    // GENERATE ARRAY
    // ======================================================

    for (int i = 0; i < n; i++) {

        double fi =
            (function_number == 1)
            ? f1(i)
            : f2(i);

        A[i] = fi + dist(rng);
    }

    sort(A.begin(), A.end());


    // ======================================================
    // GENERATE q
    // ======================================================

    uniform_int_distribution<int> coin(0, 9);

    double q;

    // 30% -> EXISTS
    if (coin(rng) < 3) {

        uniform_int_distribution<int>
            idx(0, n - 1);

        q = A[idx(rng)];
    }

    // 70% -> DOES NOT EXIST
    else {

        uniform_real_distribution<double>
            qdist(A[0], A[n - 1]);

        do {
            q = qdist(rng);
        }
        while (
            binary_search(
                A.begin(),
                A.end(),
                q
            )
        );
    }


    // ======================================================
    // OUTPUT
    // ======================================================

    cout << n << "\n";

    for (double x : A) {
        cout << x << "\n";
    }

    cout << q << "\n";

    cout << function_number << "\n";

    return 0;
}