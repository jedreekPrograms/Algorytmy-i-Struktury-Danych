#include "../include/Benchmark.h"
#include "../include/Generator.h"
#include "../include/Kruskal.h"
#include "../include/Prim.h"

#include <fstream>
#include <chrono>
#include <iostream>
#include <string>

std::string graphTypeToString(GraphType type){

    if(type==GraphType::COMPLETE){

        return "complete";
    }

    if(type==GraphType::SPARSE){

        return "sparse";
    }

    return "medium";
}

void Benchmark::run(
    int nMin,
    int nMax,
    int step,
    int rep,
    GraphType type
){

    std::string typeName=graphTypeToString(type);

    std::ofstream kr(
        "data/"+typeName+"_kruskal.csv"
    );

    std::ofstream pr(
        "data/"+typeName+"_prim.csv"
    );

    kr<<"n,time,cost\n";
    pr<<"n,time,cost\n";

    for(int n=nMin;n<=nMax;n+=step){

        double krTime=0.0;
        double prTime=0.0;

        double krCostSum=0.0;
        double prCostSum=0.0;

        for(int i=0;i<rep;i++){

            Graph g=Generator::generateGraph(n,type);

            /*
                KRUSKAL
            */

            auto start=std::chrono::high_resolution_clock::now();

            krCostSum+=Kruskal::mst(g);

            auto end=std::chrono::high_resolution_clock::now();

            krTime+=std::chrono::duration<double,std::milli>(end-start).count();

            /*
                PRIM
            */

            start=std::chrono::high_resolution_clock::now();

            prCostSum+=Prim::mst(g);

            end=std::chrono::high_resolution_clock::now();

            prTime+=std::chrono::duration<double,std::milli>(end-start).count();
        }

        /*
            srednie
        */

        krTime/=rep;
        prTime/=rep;

        double krCost=krCostSum/rep;

        double prCost=prCostSum/rep;

        /*
            zapis CSV
        */

        kr
            <<n<<","
            <<krTime<<","
            <<krCost<<"\n";

        pr
            <<n<<","
            <<prTime<<","
            <<prCost<<"\n";

        std::cout
            <<"["<<typeName<<"] "
            <<"n="<<n
            <<" done\n";
    }

    kr.close();
    pr.close();
}