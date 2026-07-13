#include "../include/Graph.h"

Graph::Graph(int n):n(n){

    adj.resize(n);
}

void Graph::addEdge(int u,int v,double w){

    edges.emplace_back(u,v,w);

    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

int Graph::getN() const{

    return n;
}