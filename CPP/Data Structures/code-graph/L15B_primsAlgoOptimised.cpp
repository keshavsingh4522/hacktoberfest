#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b, weight;
        cin >> a >> b >> weight;
        g[a].push_back({b, weight});
        g[b].push_back({a, weight});
    }

    int parent[n];

    int key[n];

    bool mstSet[n];

    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;

    // Prim's Begins
    // Priority queue of key-value as pair
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});
    // int ansWeight = 0;
    for (int count = 0; count < n - 1; count++)
    {
        // This code takes O(n) time to find min element each time which results in O(n^2)
        //-------------------------------------------
        // int mini = INT_MAX, u;
        // for (int v = 0; v < n; v++)
        //     if (mstSet[v] == false && key[v] < mini)
        //         mini = key[v], u = v;
        //-------------------------------------------

        // Using priority queue i.e. min heap gives us the min in O(log n) thus total O(n*log n) as final---
        //------------------------------------------------
        int u = pq.top().second;
        pq.pop();
        //------------------------------------------------

        mstSet[u] = true;

        for (auto it : g[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << parent[i] << " - " << i << " \n";
    return 0;
}

/*

* Input:----
8 14
0 1 4
0 7 8 
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

! Output:----
-1 - 0 
0 - 1 
1 - 2 
2 - 3 
3 - 4 
2 - 5 
5 - 6 
6 - 7
*/