#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<int> bfsGraph(int n, vector<int> arr[])
    {
        vector<int> bfs;
        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(1);
        vis[1] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : arr[node])
            {
                if (!vis[it])
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return bfs;
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
    vector<int> ans = obj.bfsGraph(n, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
        // cout << ans.size();
    }
    cout << endl;

    return 0;
}