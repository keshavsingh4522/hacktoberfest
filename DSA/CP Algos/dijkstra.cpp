#include <bits/stdc++.h>
using namespace std;

void dijkstra(int start, vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;

        for (auto& edge : adj[node]) {
            int next = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    cout << "Dijkstra Shortest Distances:\n";
    for (int i = 0; i < n; i++)
        cout << "Node " << i << ": " << dist[i] << endl;
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);

    adj[0] = {{1, 2}, {2, 4}};
    adj[1] = {{2, 1}, {3, 7}};
    adj[2] = {{4, 3}};
    adj[3] = {{4, 1}};
    adj[4] = {};

    dijkstra(0, adj);
    return 0;
}
