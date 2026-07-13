#include "../include/Kruskal.h"
#include "../include/DSU.h"

#include <algorithm>

double Kruskal::mst(Graph& g){

    auto edges=g.edges;

    std::sort(
        edges.begin(),
        edges.end(),
        [](const Edge& a,const Edge& b){

            return a.w<b.w;
        }
    );

    DSU dsu(g.getN());

    double cost=0.0;

    int usedEdges=0;

    for(const auto& e:edges){

        if(dsu.find(e.u)!=dsu.find(e.v)){

            dsu.unite(e.u,e.v);

            cost+=e.w;

            usedEdges++;

            if(usedEdges==g.getN()-1){

                break;
            }
        }
    }

    return cost;
}