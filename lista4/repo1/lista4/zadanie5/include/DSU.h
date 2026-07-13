#pragma once

#include <vector>

class DSU {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    DSU(int n);

    int find(int x);

    void unite(int a,int b);
};