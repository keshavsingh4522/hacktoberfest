#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int, int>> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            findTopoSort(it.first, vis, st, adj);
        }
    }
    st.push(node);
}

void shortestPath(int n, vector<pair<int, int>> adj[], int src)
{
    int vis[n] = {0};
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            findTopoSort(i, vis, st, adj);
        }
    }
    int dist[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (dist[node] != INT_MAX)
        {
            for (auto it : adj[node])
            {
                if (dist[node] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "The dist of " << i << " from " << src << " is ";
        (dist[i] == INT_MAX) ? cout << "INF " : cout << dist[i] << " ";
        cout << endl;
    }
}

int main()
{
    int n, m, src;

    cin >> n >> m >> src;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int a, b, weight;
        cin >> a >> b >> weight;
        adj[a].push_back({b, weight});
        //Directed Cycle
        // adj[b].push_back(a);
    }

    shortestPath(n, adj, src);

    // Solution obj;
    // bool ans;
    // ans = obj.bfs(n, adj);

    // cout << ans << "\n";
    return 0;
}

/*
! input :- 
6 9 1
0 1 5
0 2 3
1 2 2
1 3 6
2 3 7
2 5 2
2 4 4
3 4 -1
4 5 -2

* output :-
The dist of 0 from 1 is INF 
The dist of 1 from 1 is 0 
The dist of 2 from 1 is 2 
The dist of 3 from 1 is 6 
The dist of 4 from 1 is 5 
The dist of 5 from 1 is 3

*/