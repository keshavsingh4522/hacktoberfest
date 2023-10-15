/** Bellman ford is slower than dijkstra as it has runtime of O((e+v)logv)
 * but it is helpful in detecting a negative cycle, and the nodes which are reachable
 * from the negative cycle **/

#include <bits/stdc++.h>
#define pd pair<int, int>

using namespace std;

vector<int> bellmanFord(vector<vector<pd>> adj, int start, int vertices)
{

    vector<int> dist(vertices, INT_MAX);
    dist[start] = 0;

    // For each vertex, apply relaxation for all the edges
    for (int v = 0; v < vertices - 1; v++)
    {
        for (int edges = 0; edges < adj.size(); edges++)
        {
            for (auto edge : adj[edges])
            {
                if (dist[edges] + edge.second < dist[edge.first])
                    dist[edge.first] = dist[edges] + edge.second;
            }
        }
    }

    // Run algorithm a second time to detect which nodes are part
    // of a negative cycle. A negative cycle has occurred if we
    // can find a better path beyond the optimal solution.
    for (int v = 0; v < vertices - 1; v++)
    {
        for (int edges = 0; edges < adj.size(); edges++)
        {
            for (auto edge : adj[edges])
            {
                if (dist[edges] + edge.second < dist[edge.first])
                    dist[edge.first] = INT_MIN;
            }
        }
    }

    return dist;
}

int main()
{
    int n, e;
    cout << "Enter no. nodes and edges ";
    cin >> n >> e;

    cout << "\nEnter the graph\n";

    vector<vector<pd>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
    }

    int start;
    cout << "\nEnter start node ";
    cin >> start;

    cout << "\nDistance from every " << start << " to every node is \n";
    vector<int> dist = bellmanFord(adj, start, n);
    for (auto x : dist)
        cout << x << " ";
    cout << endl;
}