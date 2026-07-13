// generator_select_groups.cpp

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 4) {
        cout << "Uzycie: ./generator n seed group_size\n";
        return 1;
    }

    int n = stoi(argv[1]);
    int seed = stoi(argv[2]);

    // tylko przekazujemy dalej do programu select
    int group_size = stoi(argv[3]);

    srand(seed);

    // n
    cout << n << "\n";

    // rozmiar grupy do SELECT
    cout << group_size << "\n";

    // dane
    for (int i = 0; i < n; i++) {
        cout << rand() % (2 * n) << " ";
    }

    cout << "\n";

    return 0;
}