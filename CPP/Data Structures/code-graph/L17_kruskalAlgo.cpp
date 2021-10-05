#include <bits/stdc++.h>
using namespace std;

// KRUSKAL'S  algo finds MST.....uses disjoint set data structure
struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);

    if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else if (rank[v] > rank[u])
    {
        parent[u] = v;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> wt >> u >> v;
        edges.push_back(node(u, v, wt));
    }
    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    vector<int> rank(n, 0);

    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges)
    {
        if (findPar(it.v, parent) != findPar(it.u, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }
    cout << "Spanning cost is: " << cost << endl;
    for (auto x : mst)
    {
        cout << x.first << "-->" << x.second << endl;
    }

    return 0;
}

/*

* Input:----
9 14
wt u v
1 7 6
2 8 2
2 6 5
4 0 1
4 2 5
6 8 6
7 2 3
7 7 8
8 0 7
8 1 2
9 3 4
10 5 4
11 1 7
14 3 5

! Output:----
Spanning cost is: 37
7-->6
8-->2
6-->5
0-->1
2-->5
2-->3
0-->7
3-->4
*/