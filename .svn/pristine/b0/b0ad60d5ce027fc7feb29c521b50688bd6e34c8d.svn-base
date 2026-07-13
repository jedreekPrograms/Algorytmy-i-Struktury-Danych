#include "../include/Experiment.h"

#include "../include/Generator.h"
#include "../include/Kruskal.h"
#include "../include/BroadcastSolver.h"

#include <fstream>
#include <iostream>
#include <algorithm>

void Experiment::run(
    int nMin,
    int nMax,
    int step,
    int repetitions
){

    std::ofstream file("data/results.csv");

    file << "n,min,avg,max\n";

    for(int n=nMin;n<=nMax;n+=step){

        double minSum=0.0;
        double avgSum=0.0;
        double maxSum=0.0;

        for(int rep=0;rep<repetitions;rep++){

            Graph g=Generator::generateGraph(n);

            Tree mst=Kruskal::mst(g);

            long long roundsSum=0;

            int currentMin=1000000000;

            int currentMax=0;

            for(int root=0;root<n;root++){

                BroadcastSolver solver(mst);

                int rounds=solver.solve(root);

                roundsSum+=rounds;

                currentMin=
                    std::min(
                        currentMin,
                        rounds
                    );

                currentMax=
                    std::max(
                        currentMax,
                        rounds
                    );
            }

            double currentAvg=static_cast<double>(roundsSum)/n;

            minSum+=currentMin;
            avgSum+=currentAvg;
            maxSum+=currentMax;
        }

        double avgMin=minSum/repetitions;

        double avgAvg=avgSum/repetitions;

        double avgMax=maxSum/repetitions;

        file
            << n << ","
            << avgMin << ","
            << avgAvg << ","
            << avgMax << "\n";

        std::cout
            << "n="
            << n
            << " done\n";
    }

    file.close();
}