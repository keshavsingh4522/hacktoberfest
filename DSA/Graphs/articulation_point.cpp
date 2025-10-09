/** An articulation point is a node when removed, increases the no. of connected
 * components in a graph. Normally it can be one of the 2 nodes in a bridge,
 * but that is not certain. 
 * 
 * It can occur in 2 conditions, when there is a cycle and when there is a bridge
 * When there is a bridge, the if id(current_node) < low_link(outgoing), then it is an 
 * articulation point
 * 
 * In case of cycle, if id(current_node) == low_link(outgoing), then it is a Ap,
 * but this condition is only possible when there is at least 2 outgoing edge from
 * the current node **/

#include <bits/stdc++.h>
using namespace std;

vector<int> ids(1000, 0);
vector<int> low_link(1000, 0);
vector<bool> visited(1000, false);
vector<bool> isArtPoint(1000, false);
int id = 0;      // to store the unique ids of every node
int outEdge = 0; // to ensure the node has more than 1 outgoing edge

void dfs(vector<vector<int>> adj, int root, int at, int parent, vector<bool> isArtPoint)
{

    if (parent == root)
        outEdge++;
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
            dfs(adj, root, to, at, isArtPoint);

            // this sets the low link values in just one pass
            low_link[at] = min(low_link[at], low_link[to]);

            // Articulation point found via bridge
            if (ids[at] < low_link[to])
                isArtPoint[at] = true;

            // Articulation point found via cycle
            if (ids[at] == low_link[to])
                isArtPoint[at] = true;
        }
        else // if we visit a node previouly visited, we ensures that we have the least value of lowlink to it
            low_link[at] = min(low_link[at], low_link[to]);
    }
}

vector<bool> findArtPoint(vector<vector<int>> adj, int numNodes)
{
    for (int i = 0; i < numNodes; i++)
    {
        if (!visited[i])
        {
            outEdge = 0;
            dfs(adj, i, i, -1, isArtPoint);
            isArtPoint[i] = outEdge > 1;
        }
    }

    return isArtPoint;
}
