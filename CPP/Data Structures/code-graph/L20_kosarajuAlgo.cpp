#include <bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, st, vis, adj);
        }
    }
    st.push(node);
}

void revDfs(int node, vector<int> &vis, vector<int> transpose[])
{
    cout << node << " ";
    vis[node] = 1;
    for (auto it : transpose[node])
    {
        if (!vis[it])
        {
            revDfs(it, vis, transpose);
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
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    stack<int> st;
    vector<int> vis(n, 0);

    // Step-1: TOPO SORT and store in stack to use later
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, st, vis, adj);
        }
    }

    // Step-2: Transpose of graph to reverse all the directed edges
    vector<int> transpose[n];

    for (int i = 0; i < n; i++)
    {
        // Unmark visited array to use in DFS in step-3
        vis[i] = 0;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    // Step-3: DFS on stack formed by TOPO SORT
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            cout << "SCC: ";
            revDfs(node, vis, transpose);
            cout << endl;
        }
    }

    return 0;
}

/*
INPUT--
6 7
0 1 
1 2 
2 0 
1 3 
3 4 
4 5
5 3

OUTPUT--
SCC: 0 2 1 
SCC: 3 5 4
*/