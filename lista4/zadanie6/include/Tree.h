#pragma once

#include <vector>

class Tree {
private:
    int n;

public:

    std::vector<std::vector<int>> adj;

    Tree(int n);

    void addEdge(int u,int v);

    int getN() const;
};