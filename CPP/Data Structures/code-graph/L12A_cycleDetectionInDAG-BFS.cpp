#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCyclic(int n, vector<int> adj[])
    {
        queue<int> q;
        vector<int> indegree(n, 0);

        //populating indegree vector
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        //pushing into queue
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // BFS begins------
        // vector<int> topo;
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            // topo.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if (cnt == n)
            return false;
        else
            return true;
        // return topo;
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
    bool ans;
    ans = obj.isCyclic(n, adj);

    cout << ans << "\n";
    return 0;
}

/*
gfg link ---- https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#
input 1:- 
6 6
5 0
4 0
5 2
4 1
2 3
3 1

output 1:- 0 

input 2:- 
6 6
0 5
4 0
5 2
1 4
2 3
3 1

output 2:- 1
*/