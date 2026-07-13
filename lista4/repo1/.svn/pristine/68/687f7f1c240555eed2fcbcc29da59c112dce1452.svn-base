#include "../include/Benchmark.h"
#include "../include/GraphType.h"

int main(){

    Benchmark::run(
        100,
        3000,
        100,
        5,
        GraphType::COMPLETE
    );

    Benchmark::run(
        100,
        10000,
        500,
        5,
        GraphType::SPARSE
    );

    Benchmark::run(
        100,
        7000,
        250,
        5,
        GraphType::MEDIUM
    );

    return 0;
}