/** Depth first search
 * We keep a visited array to mark the nodes which we have already visited,
 * if not visited, mark the current node as true, and do the dfs in nodes connected
 * from the current node **/

#include <bits/stdc++.h>
using namespace std;

vector<int> component(10000, 0); // to color the nodes
int counter = 0;                 // to count the no. of connected component

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    if (visited[node])
        return;
    component[node] = counter;
    visited[node] = true;
    vector<int> neigh = adj[node];
    for (int i = 0; i < neigh.size(); i++)
        dfs(neigh[i], adj, visited);
}

pair<int, vector<int>> connectedComponents(vector<vector<int>> &adj, vector<bool> &visited)
{
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[i])
        {
            counter++;
            dfs(i, adj, visited); /** all the nodes which are connected from i are colored as
                                    counter and are under same component **/
        }
    }
    return {counter, component};
}

int main()
{
    int n, e;
    cout << "Enter no. of nodes and edges ";
    n = 13, e = 14;
    cout << "\nEnter the map ";
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y), adj[y].push_back(x);
    }
    vector<bool> visited(n + 1, false);

    pair<int, vector<int>> p = connectedComponents(adj, visited);
    cout << "No. of connected components " << p.first << endl;
    cout << "The colors are ";
    for (int i = 0; i < n + 1; i++)
        cout << p.second[i] << " ";
    cout << endl;
}
