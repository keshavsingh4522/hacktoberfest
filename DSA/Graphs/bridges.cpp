/** Brides are the edges upon removing the no. of connected component increases 
 * To do this, we will use the a property called low-link values of every node
 * low link value of a node is defined as the minimum id of a reachable node from
 * the current node
 * Hence, we will store the id of the nodes as well as the low link values **/

/** To find if a edge is a bridge, we will use a property --
 * id(edge.from) < low-link(edge.to), that means
 * if the id of current node is lesser than the low link of the node connected to it
 * then that edge is a bridge **/

#include <bits/stdc++.h>
using namespace std;

vector<int> ids(1000, 0);
vector<int> low_link(1000, 0);
vector<bool> visited(1000, false);
int id = 0; // to store the unique ids of every node

void dfs(vector<vector<int>> adj, int at, int parent, vector<int> &bridges)
{
    visited[at] = true;
    id++;
    ids[at] = low_link[at] = id;

    for (auto to : adj[at])
    {
        // since it is an undirected graph, it will certainly happen
        if (to == parent)
            continue;

        if (!visited[to])
        {
            dfs(adj, to, at, bridges);

            // this sets the low link values in just one pass
            low_link[at] = min(low_link[at], low_link[to]);

            // we check this condition for the edge to be a bridge
            if (ids[at] < low_link[to])
                bridges.push_back(at), bridges.push_back(to);
        }
        else // if we visit a node previouly visited, we ensures that we have the least value of lowlink to it
            low_link[at] = min(low_link[at], low_link[to]);
    }
}

vector<int> findBridges(vector<vector<int>> adj, int numNodes)
{
    vector<int> bridges;
    for (int i = 0; i < numNodes; i++)
    {
        // we pass -1 as the parent of 1st node is none
        if (!visited[i])
            dfs(adj, i, -1, bridges);
    }

    return bridges;
}