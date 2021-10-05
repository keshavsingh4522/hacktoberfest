#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[])
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;

        if (!vis[it])
        {
            dfs(it, node, vis, tin, low, timer, adj);
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node])
            {
                cout << node << "--" << it << endl;
            }
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
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
    // tin --> stores intime
    vector<int> tin(n, -1);
    // lwo --> lowest intime if cycle
    vector<int> low(n, -1);
    // vis --> visited for DFS
    vector<int> vis(n, 0);
    int timer = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, tin, low, timer, adj);
        }
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
8--9
5--6
4--5
3--4
*/