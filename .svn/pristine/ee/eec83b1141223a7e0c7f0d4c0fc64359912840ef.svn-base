#include "../include/Generator.h"

#include <random>
#include <set>
#include <cmath>

Graph Generator::generateGraph(int n,GraphType type){

    Graph g(n);

    static std::mt19937 gen(
        std::random_device{}()
    );

    std::uniform_real_distribution<double>
        weightDist(0.0,1.0);

    auto randomWeight=[&](){

        return weightDist(gen);
    };

    /*
        COMPLETE GRAPH
    */

    if(type==GraphType::COMPLETE){

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                g.addEdge(
                    i,
                    j,
                    randomWeight()
                );
            }
        }
    }

    /*
        SPARSE GRAPH
    */

    else if(type==GraphType::SPARSE){

        /*
            losowe drzewo spinajace
        */

        for(int i=1;i<n;i++){

            std::uniform_int_distribution<int>
                parentDist(0,i-1);

            int parent=parentDist(gen);

            g.addEdge(
                i,
                parent,
                randomWeight()
            );
        }

        /*
            dodatkowe krawedzie
        */

        int extraEdges=n;

        std::set<std::pair<int,int>> used;

        for(const auto& e:g.edges){

            used.insert({
                std::min(e.u,e.v),
                std::max(e.u,e.v)
            });
        }

        while(extraEdges>0){

            std::uniform_int_distribution<int>
                vertexDist(0,n-1);

            int u=vertexDist(gen);
            int v=vertexDist(gen);

            if(u==v){

                continue;
            }

            int a=std::min(u,v);
            int b=std::max(u,v);

            if(used.count({a,b})){

                continue;
            }

            used.insert({a,b});

            g.addEdge(
                u,
                v,
                randomWeight()
            );

            extraEdges--;
        }
    }

    /*
        MEDIUM GRAPH
    */

    else if(type==GraphType::MEDIUM){

        int targetEdges=
            static_cast<int>(
                n*std::log2(n)
            );

        /*
            drzewo spinajace
        */

        for(int i=1;i<n;i++){

            std::uniform_int_distribution<int>
                parentDist(0,i-1);

            int parent=parentDist(gen);

            g.addEdge(
                i,
                parent,
                randomWeight()
            );
        }

        std::set<std::pair<int,int>> used;

        for(const auto& e:g.edges){

            used.insert({
                std::min(e.u,e.v),
                std::max(e.u,e.v)
            });
        }

        int currentEdges=n-1;

        while(currentEdges<targetEdges){

            std::uniform_int_distribution<int>
                vertexDist(0,n-1);

            int u=vertexDist(gen);
            int v=vertexDist(gen);

            if(u==v){

                continue;
            }

            int a=std::min(u,v);
            int b=std::max(u,v);

            if(used.count({a,b})){

                continue;
            }

            used.insert({a,b});

            g.addEdge(
                u,
                v,
                randomWeight()
            );

            currentEdges++;
        }
    }


    return g;
}