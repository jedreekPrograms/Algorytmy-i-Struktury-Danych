#include "../include/Generator.h"

#include <random>

Graph Generator::generateGraph(int n){

    Graph g(n);

    static std::mt19937 gen(
        std::random_device{}()
    );

    std::uniform_real_distribution<double>
        dist(0.0,1.0);

    for(int i=0;i<n;i++){

        for(int j=i+1;j<n;j++){

            g.addEdge(
                i,
                j,
                dist(gen)
            );
        }
    }

    return g;
}