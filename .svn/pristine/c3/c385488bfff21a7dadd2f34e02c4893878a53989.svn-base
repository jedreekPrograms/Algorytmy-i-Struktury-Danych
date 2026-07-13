#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>

using namespace std;

void runCommand(const string& cmd)
{
    int result = system(cmd.c_str());

    if(result != 0)
    {
        cerr << "Błąd podczas wykonywania: " << cmd << endl;
        exit(1);
    }
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    cout << "=== CZYSZCZENIE ===" << endl;

    runCommand("del /Q *.txt *.png *.exe input.txt 2>nul");

    cout << "=== KOMPILOWANIE ===" << endl;

    runCommand("g++ -O2 -std=c++17 BinarySearch.cpp BinarySearch_main.cpp -o binary.exe");
    runCommand("g++ -O2 -std=c++17 MyFind.cpp MyFind_main.cpp -o myfind.exe");
    runCommand("g++ -O2 -std=c++17 generator.cpp -o generator.exe");

    cout << "=== MAŁE TESTY ===" << endl;

    for(int n : {8, 20})
    {
        for(int f = 1; f <= 2; ++f)
        {
            string gen =
                "generator.exe " +
                to_string(n) +
                " " +
                to_string(f) +
                " > input.txt";

            runCommand(gen);

            runCommand("binary.exe < input.txt >> binary_small.txt");
            runCommand("myfind.exe < input.txt >> myfind_small.txt");
        }
    }

    cout << "=== DUŻE TESTY ===" << endl;

    for(int n = 1000; n <= 300000; n += 1000)
    {
        for(int rep = 1; rep <= 5; ++rep)
        {
            for(int f = 1; f <= 2; ++f)
            {
                string gen =
                    "generator.exe " +
                    to_string(n) +
                    " " +
                    to_string(f) +
                    " > input.txt";

                runCommand(gen);

                string bin =
                    "binary.exe < input.txt >> binary_" +
                    to_string(f) +
                    ".txt";

                string myf =
                    "myfind.exe < input.txt >> myfind_" +
                    to_string(f) +
                    ".txt";

                runCommand(bin);
                runCommand(myf);
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();

    double elapsed =
        chrono::duration<double>(end - start).count();

    cout << "\n=== GOTOWE ===" << endl;
    cout << "Czas wykonania: " << elapsed << " s" << endl;

    return 0;
}