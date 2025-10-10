#include <bits/stdc++.h>
using namespace std;

void BFS(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int n = 5;
    vector<vector<int>> adj = {
        {1, 2}, {0, 3, 4}, {0, 4}, {1}, {1, 2}
    };

    BFS(0, adj);
    return 0;
}
