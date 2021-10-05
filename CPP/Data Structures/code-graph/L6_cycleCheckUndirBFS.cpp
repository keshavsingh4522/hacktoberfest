#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    bool checkForCycle(int s, int n, vector<int> adj[], vector<int> &vis)
    {
        queue<pair<int, int>> q;
        vis[s] = true;
        q.push({s, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int n, vector<int> adj[])
    {
        vector<int> vis(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, n, adj, vis))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    int m, n;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solution obj;
    bool ans = obj.isCycle(n, adj);
    if (ans)
    {
        cout << "Present";
    }
    else
    {
        cout << "Absent";
    }
    cout << endl;

    return 0;
}