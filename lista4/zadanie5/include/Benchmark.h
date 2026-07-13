#pragma once

#include "GraphType.h"

class Benchmark {
public:
    static void run(
        int nMin,
        int nMax,
        int step,
        int rep,
        GraphType type
    );
};