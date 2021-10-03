#include <bits/stdc++.h>

using namespace std;

int Nodes; // number of nodes
int Edges; // number of edges
vector<int> Graph[N+1]; // adjecency list
vector<int> parent(N+1); 
vector<int> rank(N+1);

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}


int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main() {
    
    // Input
    cin>>N>>E;
    for(int i=0;i<Edges;i++)
    {
        int u,v;
        cin>>u>>v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    
    for(int i=0;i<Nodes;i++)
    {
        make_set(i);
    }
    
    // use the dsu algorithm as per use case 
}

