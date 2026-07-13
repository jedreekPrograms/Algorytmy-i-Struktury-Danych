#include "../include/Prim.h"

#include <queue>
#include <vector>
#include <functional>
#include <limits>

double Prim::mst(Graph& g){

    int n=g.getN();

    using P=std::pair<double,int>;

    std::priority_queue<
        P,
        std::vector<P>,
        std::greater<P>
    > pq;

    std::vector<bool> visited(n,false);

    std::vector<double> best(
        n,
        std::numeric_limits<double>::infinity()
    );

    best[0]=0.0;

    pq.push({0.0,0});

    double cost=0.0;

    while(!pq.empty()){

        auto [w,v]=pq.top();

        pq.pop();

        if(visited[v]){

            continue;
        }

        visited[v]=true;

        cost+=w;

        for(auto [to,weight]:g.adj[v]){

            if(
                !visited[to]
                &&
                weight<best[to]
            ){

                best[to]=weight;

                pq.push({weight,to});
            }
        }
    }

    return cost;
}