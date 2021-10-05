#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;

        if (!vis[it])
        {
            dfs(it, node, vis, tin, low, timer, adj, isArticulation);
            low[node] = min(low[node], low[it]);
            child++;
            if (low[it] >= tin[node] && parent != -1)
            {
                isArticulation[node] = 1;
            }
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }

    if (parent == -1 && child > 1)
    {
        isArticulation[node] = 1;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    vector<int> vis(n, 0);
    vector<int> isArticulation(n, 0);
    int timer = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, tin, low, timer, adj, isArticulation);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (isArticulation[i] == 1)
            cout << i << endl;
    }

    return 0;
}

/*
* Input:----
10 11
0 1
1 2
2 3
0 3
3 4
4 5
5 6
6 7
7 8
6 8
8 9

! Output:----
3
4
5
6
8
*/