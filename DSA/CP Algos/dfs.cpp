#include <bits/stdc++.h>
using namespace std;

void DFSUtil(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            DFSUtil(neighbor, adj, visited);
    }
}

void DFS(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    cout << "DFS Traversal: ";
    DFSUtil(start, adj, visited);
    cout << endl;
}

int main() {
    int n = 5;
    vector<vector<int>> adj = {
        {1, 2}, {0, 3, 4}, {0, 4}, {1}, {1, 2}
    };

    DFS(0, adj);
    return 0;
}
