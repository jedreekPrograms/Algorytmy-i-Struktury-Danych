#pragma once

#include "Tree.h"

#include <vector>

class BroadcastSolver {

private:

    Tree& tree;

    std::vector<int> dp;

    std::vector<
        std::vector<int>
    > order;

    void dfs(
        int v,
        int parent
    );

public:

    BroadcastSolver(
        Tree& tree
    );

    int solve(
        int root
    );

    const std::vector<
        std::vector<int>
    >& getOrder() const;
};