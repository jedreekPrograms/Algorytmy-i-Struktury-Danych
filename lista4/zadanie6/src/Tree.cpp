#include "../include/Tree.h"

Tree::Tree(int n):n(n){

    adj.resize(n);
}

void Tree::addEdge(int u,int v){

    adj[u].push_back(v);
    adj[v].push_back(u);
}

int Tree::getN() const{

    return n;
}