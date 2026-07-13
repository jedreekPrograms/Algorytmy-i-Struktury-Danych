#include "../include/BroadcastSolver.h"

#include <algorithm>

BroadcastSolver::BroadcastSolver(Tree& tree):tree(tree){
    int n=tree.getN();

    dp.resize(n);

    order.resize(n);
}

void BroadcastSolver::dfs(int v,int parent){

    std::vector<std::pair<int,int>> children;

    for(int u : tree.adj[v]){

        if(u==parent){

            continue;
        }

        dfs(u,v);

        children.push_back({dp[u],u});
    }

    std::sort(children.begin(),children.end(),[](auto& a,auto& b){

            return a.first>b.first;
        }
    );

    order[v].clear();

    int answer=0;

    for(int i=0;i<(int)children.size();i++){

        int child=children[i].second;

        int childTime=children[i].first;

        order[v].push_back(child);

        answer=
            std::max(
                answer,
                (i+1)+childTime
            );
    }

    dp[v]=answer;
}

int BroadcastSolver::solve(int root){

    dfs(root,-1);

    return dp[root];
}

const std::vector<
    std::vector<int>>& BroadcastSolver::getOrder() const{

    return order;
}