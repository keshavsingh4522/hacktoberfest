#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(vector<int> adj[], int n, int src)
    {
        queue<int> q;
        vector<int> vis(n + 1, 0);
        vector<int> dist(n + 1, 0);
        q.push(src);
        vis[src] = 1;
        dist[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    q.push(it);
                    dist[it] = dist[node] + 1;
                    vis[it] = 1;
                }
            }
        }
        //Print shortest dist
        for (int i = 1; i <= n; i++)
        {
            cout << "The dist to " << i << " is " << dist[i] << endl;
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    Solution obj;
    obj.bfs(adj, n, 1);

    return 0;
}