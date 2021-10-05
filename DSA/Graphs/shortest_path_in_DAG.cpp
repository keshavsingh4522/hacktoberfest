/** Directed Acyclic graph or DAG's shortest and longest path can be found using
 * topological sort in O(v+e) **/
// We will find shortest path from start to every individual nodes

/** To find the longest path in a DAG, we first negate all the weights, and find
 * the shortest path of all the paths, then multiply the path by -1 **/

#include <bits/stdc++.h>
using namespace std;

const int MAX = INT32_MAX;

int dfs(int i, int node, vector<int> &ordering, vector<vector<pair<int, int>>> adj,
        vector<bool> &vis)
{
    vis[node] = true;
    vector<pair<int, int>> neighbour = adj[node];

    for (auto next : neighbour)
    {
        if (!vis[next.first])
            i = dfs(i, next.first, ordering, adj, vis);
    }

    ordering[i] = node; // we push the current node in the list of visited to maintain the order
    return i - 1;
}

vector<int> topologicalSort(vector<vector<pair<int, int>>> adj, int N)
{
    vector<bool> vis(N, false);
    vector<int> ordering(N, 0);
    int i = N - 1;                 // we start from last because visit the end nodes first
    for (int at = 0; at < N; at++) // we keep doing this until all the nodes are not visited
    {
        if (!vis[at])
            i = dfs(i, at, ordering, adj, vis);
    }

    return ordering;
}

// first pair contains the outgoing edges, second contains its weight
vector<int> minDistance(vector<vector<pair<int, int>>> adj, int start, int numNodes)
{
    vector<int> distance(numNodes, MAX);
    vector<int> topOrder = topologicalSort(adj, numNodes);

    distance[start] = 0;

    // We will start traversing in topological order
    for (int i = 0; i < numNodes; i++)
    {
        int nodeIndex = topOrder[i];
        if (distance[nodeIndex] != MAX)
        {
            vector<pair<int, int>> adjacentEdge = adj[nodeIndex];
            if (adjacentEdge.size() > 0)
            {
                for (auto edge : adjacentEdge)
                {
                    int newDist = distance[nodeIndex] + edge.second;
                    if (distance[edge.first] == MAX)
                        distance[edge.first] = newDist;
                    else
                        distance[edge.first] = min(distance[edge.first], newDist);
                }
            }
        }
    }

    return distance;
}

int main()
{
    int n, e;
    cout << "Enter no. nodes and edges ";
    cin >> n >> e;

    cout << "\nEnter the graph\n";

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
    }

    int start;
    cout << "\nEnter start node ";
    cin >> start;

    cout << "\nDistance from " << start << " to every node \n";

    vector<int> dist = minDistance(adj, start, n);
    for (auto x : dist)
        cout << x << " ";
    cout << endl;
}