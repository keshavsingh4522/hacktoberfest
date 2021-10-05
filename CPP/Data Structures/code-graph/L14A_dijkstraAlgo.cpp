#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, src;

    cin >> n >> m >> src;
    vector<pair<int, int>> g[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b, weight;
        cin >> a >> b >> weight;
        g[a].push_back({b, weight});
        g[b].push_back({a, weight});
    }

    //Dijkstra's begins

    //MIN HEAP
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int, int>>::iterator it;
        for (it = g[prev].begin(); it != g[prev].end(); it++)
        {
            int next = it->first;
            int nextDis = it->second;

            if (dist[next] > dist[prev] + nextDis)
            {
                dist[next] = dist[prev] + nextDis;
                pq.push({dist[next], next});
            }
        }
    }
    cout << "The distances from source " << src << " are : \n";
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);

    return 0;
}

/*
Input:--
8 14 0
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

Output:----
The distances from source 0 are : 
0 		 0
1 		 4
2 		 12
3 		 19
4 		 21
5 		 11
6 		 9
7 		 8

*/