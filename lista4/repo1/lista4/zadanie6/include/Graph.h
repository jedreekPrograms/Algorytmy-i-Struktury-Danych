#pragma once

#include <vector>
#include <utility>

#include "Edge.h"

class Graph {
private:
    int n;

public:
    std::vector<Edge> edges;

    std::vector<std::vector<std::pair<int,double>>> adj;

    Graph(int n);

    void addEdge(int u,int v,double w);

    int getN() const;
};