#include "../include/Kruskal.h"
#include "../include/DSU.h"

#include <algorithm>

Tree Kruskal::mst(Graph& g){

    auto edges=g.edges;

    std::sort(
        edges.begin(),
        edges.end(),
        [](const Edge& a,const Edge& b){

            return a.w<b.w;
        }
    );

    Tree mst(g.getN());

    DSU dsu(g.getN());

    int usedEdges=0;

    for(const auto& e:edges){

        if(dsu.find(e.u)!=dsu.find(e.v)){

            dsu.unite(e.u,e.v);

            mst.addEdge(
                e.u,
                e.v
            );

            usedEdges++;

            if(usedEdges==g.getN()-1){
                break;
            }
        }
    }

    return mst;
}