/** Floyd Warshall is good for graphs having few hundred edges, as it has
 *  a runtime of O(v^3), but it is a APSP graph - meaning
 *  All Pair Shortest Path, it gives the shortest path between all the pairs **/

/** It uses a adjacency matrix to store the graph, and it uses dynamic programming
 *  to find the optimal way from node i to node j **/

/** Basically, it finds the shortest path from node i to j through a node k,
 *  it finds the distance between i -> k + k-> j and i -> j
 *  then updates the shortest path among the two **/

/** To show the adjacency matrix, we can put infinity to the nodes
 *  from which current node is not reachable **/

#include <bits/stdc++.h>
using namespace std;

const long long MAX = 1e16;

void setup(vector<vector<int>> adj, vector<vector<int>> &dp, vector<vector<int>> &next, int numNodes)
{
    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < numNodes; j++)
        {
            dp[i][j] = adj[i][j];
            if (adj[i][j] != MAX)
                next[i][j] = j;
            // this is the shortest distance from i to j initially
        }
    }
}

void propagateNegativeCycle(vector<vector<int>> dp, vector<vector<int>> next, int numNodes)
{

    /** Run the FW algorithm a second time and if we find a distance lesser than the previous
     * that means those nodes are a part of a negative cycle and we mark them **/
    for (int k = 0; k < numNodes; k++)
    {
        for (int i = 0; i < numNodes; i++)
        {
            for (int j = 0; j < numNodes; j++)
            {
                if (dp[i][k] + dp[k][j] < dp[i][j])
                    dp[i][j] = INT32_MIN, next[i][j] = -1;
                // if the distance than previous, we encounter a cycle
            }
        }
    }
}

vector<vector<int>> floydWarshall(vector<vector<int>> adj, vector<vector<int>> dp, int numNodes)
{
    vector<vector<int>> next(numNodes, vector<int>(numNodes, 0));
    setup(adj, dp, next, numNodes);

    for (int k = 0; k < numNodes; k++)
    {
        for (int i = 0; i < numNodes; i++)
        {
            for (int j = 0; j < numNodes; j++)
            {
                if (dp[i][k] + dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k] + dp[k][j], next[i][j] = next[i][k];
                // if the distance is lesser in going through other nodes
                // then we update the distance from i to j as going from k in the 'next' array
            }
        }
    }

    // go through here to ensure that graph doesnt have a negative cycle
    propagateNegativeCycle(dp, next, numNodes);

    return dp;
}