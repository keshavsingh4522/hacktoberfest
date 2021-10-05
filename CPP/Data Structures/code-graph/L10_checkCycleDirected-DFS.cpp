#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[])
    {
        vis[node] = 1;
        dfsVis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (checkCycle(it, adj, vis, dfsVis))
                {
                    return true;
                }
            }
            else if (dfsVis[it])
            {
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }

public:
    bool isCycle(int n, vector<int> adj[])
    {
        int vis[n], dfsVis[n];
        memset(vis, 0, sizeof(vis));
        memset(dfsVis, 0, sizeof(dfsVis));

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (checkCycle(i, adj, vis, dfsVis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

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
        //Directed Cycle
        // adj[b].push_back(a);
    }

    Solution obj;
    bool ans = obj.isCycle(n, adj);
    if (ans)
        cout << "Cycle Exists" << endl;
    else
        cout << "No Cycle Found" << endl;
    return 0;
}
