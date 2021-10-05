#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // declare the adjacent matrix
    vector<int> adj[n + 1];

    // take edges as input
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //Print AdjList
    for (int i = 1; i <= n; i++)
    {
        cout << i << "-->";
        for (auto x : adj[i])
        {
            cout << x << ", ";
        }
        cout << endl;
    }

    return 0;
}