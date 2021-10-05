#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     void bfs(int n,vector<int> adj[],int src)
//     {

//     }
// };

void bfs(int n, vector<int> adj[], int src)
{
    int dis[n];
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    queue<int> q;
    dis[src] = 0;
    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dis[node] + 1 < dis[it])
            {
                dis[it] = dis[node] + 1;
                q.push(it);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Distance from " << src << " to " << i << " is: ";
        cout << dis[i];
        cout << endl;
    }
}

int main()
{
    int n, m, src;

    cin >> n >> m >> src;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        //Directed Cycle
        // adj[b].push_back(a);
    }

    bfs(n, adj, src);

    // Solution obj;
    // bool ans;
    // ans = obj.bfs(n, adj);

    // cout << ans << "\n";
    return 0;
}

/*
! input :- 
8 9 0
0 1
1 2
0 3
3 4
4 5
3 7
4 7
5 6
4 6
6 7


* output :-
Distance from 0 to 0 is: 0
Distance from 0 to 1 is: 1
Distance from 0 to 2 is: 2
Distance from 0 to 3 is: 1
Distance from 0 to 4 is: 2
Distance from 0 to 5 is: 3
Distance from 0 to 6 is: 3
Distance from 0 to 7 is: 2

*/