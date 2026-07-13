// benchmark_groups.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <chrono>

#include "Select.h"

using namespace std;

/*
    IDENTYCZNY generator jak generator_select_groups.cpp
*/

vector<int> generate_data(int n, int seed) {

    srand(seed);

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        data[i] = rand() % (2 * n);
    }

    return data;
}

void run_test(
    vector<int> data,
    int n,
    int group_size,
    ofstream &out
) {

    int swaps = 0;
    int comparisons = 0;

    auto start = chrono::high_resolution_clock::now();

    int result = Select(
        data.data(),
        0,
        n - 1,
        n / 2 + 1,
        group_size,
        &swaps,
        &comparisons
    );

    auto end = chrono::high_resolution_clock::now();

    long long time =
        chrono::duration_cast<chrono::microseconds>(
            end - start
        ).count();

    // IDENTYCZNY FORMAT OUTPUTU
    out << n
        << " "
        << group_size
        << " "
        << swaps
        << " "
        << comparisons
        << " "
        << time
        << "\n";
}

int main() {

    vector<int> groups = {
        3,
        5,
        7,
        9,
        19,
        21
    };

    vector<ofstream> files;

    for (int g : groups) {

        files.emplace_back(
            "select_" + to_string(g) + ".txt"
        );
    }

    const int m = 50;

    for (int n = 100; n <= 50000; n += 100) {

        cout << "n=" << n << endl;

        for (int seed = 1; seed <= m; seed++) {

            for (size_t i = 0; i < groups.size(); i++) {

                int group_size = groups[i];

                vector<int> data =
                    generate_data(n, seed);

                run_test(
                    data,
                    n,
                    group_size,
                    files[i]
                );
            }
        }
    }

    cout << "DONE\n";

    return 0;
}