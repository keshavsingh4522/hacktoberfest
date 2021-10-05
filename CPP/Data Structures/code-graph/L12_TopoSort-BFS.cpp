#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int n, vector<int> adj[])
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
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
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

output:- 4 5 0 2 3 1 (one of the outputs)
*/