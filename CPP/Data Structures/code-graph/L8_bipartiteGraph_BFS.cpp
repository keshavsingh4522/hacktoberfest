#include <bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int src, vector<int> adj[], int color[])
{
    queue<int> q;
    q.push(src);
    color[src] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n)
{
    int color[n];
    memset(color, -1, sizeof(color));
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteBfs(i, adj, color))
                return false;
        }
    }
    return true;
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
        adj[b].push_back(a);
    }

    if (checkBipartite(adj, n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

/*
8 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 

Yes


7 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 1
4 5 

No

*/