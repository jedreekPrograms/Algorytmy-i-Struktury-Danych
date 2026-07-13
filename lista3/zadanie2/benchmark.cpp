// benchmark.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "../zadanie1/RandomizedSelect.h"
#include "../zadanie1/Select.h"

using namespace std;

// potrzebne przez algorytmy
int GLOBAL_NUMBER = 0;

/*
    Generator IDENTYCZNY jak generator_random.cpp
*/
vector<int> generate_data(int n, int seed) {

    srand(seed);

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        data[i] = rand() % (2 * n);
    }

    return data;
}

void run_randomized(
    vector<int> data,
    int n,
    int k,
    ofstream &out
) {

    int swaps = 0;
    int comparisons = 0;

    RandomizedSelect(
        data.data(),
        0,
        n - 1,
        k,
        &swaps,
        &comparisons
    );

    // IDENTYCZNY FORMAT
    out << n
        << " "
        << k
        << " "
        << swaps
        << " "
        << comparisons
        << "\n";
}

void run_select(
    vector<int> data,
    int n,
    int k,
    ofstream &out
) {

    int swaps = 0;
    int comparisons = 0;

    Select(
        data.data(),
        0,
        n - 1,
        k,
        &swaps,
        &comparisons
    );

    // IDENTYCZNY FORMAT
    out << n
        << " "
        << k
        << " "
        << swaps
        << " "
        << comparisons
        << "\n";
}

int main() {

    ofstream random_k1("random_k1.txt");
    ofstream random_kmid("random_kmid.txt");
    ofstream random_kn("random_kn.txt");

    ofstream select_k1("select_k1.txt");
    ofstream select_kmid("select_kmid.txt");
    ofstream select_kn("select_kn.txt");

    const int m = 50;

    for (int n = 100; n <= 50000; n += 100) {

        cout << "n=" << n << endl;

        for (int i = 0; i < m; i++) {

            int k1 = 1;
            int kmid = n / 2;
            int kn = n;

            // dokładnie jak w bashu:
            // osobny seed dla każdego przypadku

            /*
                k = 1
            */
            {
                vector<int> data = generate_data(n, i);

                run_randomized(
                    data,
                    n,
                    k1,
                    random_k1
                );

                run_select(
                    data,
                    n,
                    k1,
                    select_k1
                );
            }

            /*
                k = n/2
            */
            {
                vector<int> data = generate_data(n, i);

                run_randomized(
                    data,
                    n,
                    kmid,
                    random_kmid
                );

                run_select(
                    data,
                    n,
                    kmid,
                    select_kmid
                );
            }

            /*
                k = n
            */
            {
                vector<int> data = generate_data(n, i);

                run_randomized(
                    data,
                    n,
                    kn,
                    random_kn
                );

                run_select(
                    data,
                    n,
                    kn,
                    select_kn
                );
            }
        }
    }

    cout << "DONE\n";

    return 0;
}