#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void findTopoSort(int node, vector<int> adj[], stack<int> &st, vector<int> &vis)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                findTopoSort(it, adj, st, vis);
            }
        }
        st.push(node);
    }

public:
    vector<int> topoSort(int n, vector<int> adj[])
    {
        vector<int> vis(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                findTopoSort(i, adj, st, vis);
            }
        }
        vector<int> topo;
        while (!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
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
    vector<int> ans;
    ans = obj.topoSort(n, adj);

    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}

/*
input:- 
6 6
5 0
4 0
5 2
4 1
2 3
3 1

output:- 5 4 2 3 1 0 (one of the outputs)
*/