/** We find the order in which when traversed it gives an order such that 
 * all the nodes goes to the right when they are linearly arranged **/

#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int node, vector<int> &ordering, vector<vector<int>> adj, vector<bool> &vis)
{
    vis[node] = true;
    vector<int> neighbour = adj[node];

    for (auto next : neighbour)
    {
        if (!vis[next])
            i = dfs(i, next, ordering, adj, vis);
    }

    ordering[i] = node; // we push the current node in the list of visited to maintain the order
    return i - 1;
}

vector<int> topologicalSort(vector<vector<int>> adj, int N)
{
    vector<bool> vis(N, false);
    vector<int> ordering(N, 0);
    int i = N - 1;                 // we start from last because visit the end nodes first
    for (int at = 0; at < N; at++) // we keep doing this until all the nodes are not visited
    {
        if (!vis[at])
            i = dfs(i, at, ordering, adj, vis);
    }

    return ordering;
}

/** Another approach for topological sort is called Kahn's Algorithm,
 * here we maintain the in_degree of every node
 * In_degree - no. of incoming edges in a graph
 * we can also use it to detect cycles, in a DAG, let u to v be the acyclic longest
 * path, that means in_degree(u) = 0 and in_degree(v) = 1
 * 
 * We can do the following, keep track of every node's in_degree
 * and store in a queue the nodes whose in_degree is 0
 * then we go pop the queue, store the topological order and visit all the 
 * connected nodes and update the in_degree of nodes as -1 of current, then if any node
 * has in_degree == 0, push it in queue and keep the count of the no. of nodes visited,
 * if cnt < no. of nodes, then graph has a cycle **/

vector<int> TopSortKahn(vector<vector<int>> adj, int n)
{

    int cnt = 0; // no. of nodes visited
    vector<int> in_degree(n, 0);
    vector<int> top_order;
    for (int i = 0; i < n; i++)
    {
        for (auto next : adj[i])
            in_degree[next]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (in_degree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        top_order.push_back(x);

        for (auto next : adj[x])
        {
            if (--in_degree[next] == 0)
                q.push(next);
        }

        cnt++;
    }

    if (cnt != n)
        return {-1};

    return top_order;
}

int main()
{
    int n, e;
    cout << "Enter no. nodes and edges ";
    cin >> n >> e;

    vector<vector<int>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    vector<int> ordering = topologicalSort(adj, n);
    cout << "Topological ordering normal \n";
    for (auto x : ordering)
        cout << x << " ";
    cout << endl;

    ordering = TopSortKahn(adj, n);
    cout << "Topological ordering Kahn's \n";
    for (auto x : ordering)
        cout << x << " ";
    cout << endl;
}