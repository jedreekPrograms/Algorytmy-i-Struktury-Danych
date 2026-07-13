// generator_random.cpp

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 4) {
        cout << "Uzycie: ./generator n seed k\n";
        return 1;
    }

    int n = stoi(argv[1]);
    int seed = stoi(argv[2]);
    int k = stoi(argv[3]);

    srand(seed);

    cout << n << "\n";
    cout << k << "\n";
    cout << 0 << "\n";

    for (int i = 0; i < n; i++) {
        cout << rand() % (2 * n) << " ";
    }

    cout << "\n";

    return 0;
}
