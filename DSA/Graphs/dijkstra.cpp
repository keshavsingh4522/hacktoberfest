/** Dijkstra shortest path, it uses a min heap priority queue sorted by the weight
 * of the node, it takes O(E*log(v)) depending on how we implement the queue **/

// this method is also called lazy implementation because we push the same nodes again
// when their distance updates, we can do some optimization for it
// also because it is easy to insert value in the pq in O(log(n)) than to search
// and update the value

/** In the eager version of dijkstra, we can use an indexed pq, where
 * we can update the values of weights and we dont have to duplicate **/

// SSSP - Single source shortest path this means we can find shortest distance from source
// to every other node

#include <bits/stdc++.h>
#include <queue>
#define pd pair<int, int> // first is the node, second is edge weight
using namespace std;

struct myComp
{
    constexpr bool operator()(
        pair<int, int> const &a,
        pair<int, int> const &b)
        const noexcept
    {
        return a.second > b.second;
    }
};

/** Here we greedily push the values in the pq, having the least distance from
 * the current node, this only applies when all the edge weights are +ve **/

pair<vector<int>, vector<int>> dijkstra(vector<vector<pd>> adj, int numNodes, int start)
{
    bool visited[numNodes] = {false};
    vector<int> dist(numNodes, INT_MAX);
    // to show the min path we store the parent values in array
    vector<int> prev(numNodes, -1);
    dist[start] = 0;
    priority_queue<pd, vector<pd>, myComp> q;
    q.push({start, 0});
    while (!q.empty())
    {
        int index = q.top().first, minValue = q.top().second;
        q.pop();
        visited[index] = true;

        if (dist[index] < minValue) // to avoid pushing duplicate nodes when distance updates
            continue;

        for (auto edge : adj[index])
        {
            if (visited[edge.first])
                continue;

            int newDist = dist[index] + edge.second;
            // we want to update the distance of the next node from the current one
            if (newDist < dist[edge.first])
            {
                prev[edge.first] = index;
                dist[edge.first] = newDist;
                q.push({edge.first, newDist});
            }
        }
    }

    return {dist, prev};
}

// to find the minimum path route
vector<int> findShortestPath(vector<vector<pd>> adj, int start, int end, int numNodes)
{
    vector<int> prev = dijkstra(adj, numNodes, start).second;
    vector<int> dist = dijkstra(adj, numNodes, start).first;

    vector<int> path;

    if (dist[end] == INT_MAX)
        return {};

    for (auto at = end; at != -1; at = prev[at])
        path.push_back(at);

    reverse(path.begin(), path.end());
    return path;
}

/** If we want to find shortest distance to one particular node, we can stop early if we encounter
 * the node, since dijkstra is greedy, once a node is visited, its distance doesnt change
 * on futher iterations so we can stop early**/

int dijkstraEarly(vector<vector<pd>> adj, int numNodes, int start, int end)
{
    bool visited[numNodes] = {false};
    vector<int> dist(numNodes, INT_MAX);
    // to show the min path we store the parent values in array
    vector<int> prev(numNodes, -1);
    dist[start] = 0;
    priority_queue<pd, vector<pd>, myComp> q;
    q.push({start, 0});
    while (!q.empty())
    {
        int index = q.top().first, minValue = q.top().second;
        q.pop();
        visited[index] = true;

        if (dist[index] < minValue) // to avoid pushing duplicate nodes when distance updates
            continue;

        for (auto edge : adj[index])
        {
            if (visited[edge.first])
                continue;

            int newDist = dist[index] + edge.second;
            // we want to update the distance of the next node from the current one
            if (newDist < dist[edge.first])
            {
                prev[edge.first] = index;
                dist[edge.first] = newDist;
                q.push({edge.first, newDist});
            }
        }

        if (index == end)
            return dist[end];
    }

    return INT_MAX;
}

int main()
{
    int n, e;
    cout << "Enter no. nodes and edges ";
    cin >> n >> e;

    cout << "\nEnter the graph\n";

    vector<vector<pd>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
    }

    int start;
    cout << "\nEnter start node ";
    cin >> start;

    int end;
    cout << "\nEnter end node ";
    cin >> end;

    cout << "\nDistance from " << start << " to every node \n";
    vector<int> dist = dijkstra(adj, n, start).first;
    for (auto x : dist)
        cout << x << " ";
    cout << endl;

    cout << "\n Shortest path from " << start << " till " << end << " \n";
    vector<int> path = findShortestPath(adj, start, end, n);
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    cout << endl;
}