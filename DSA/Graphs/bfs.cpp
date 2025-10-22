/** In bfs, we traverse the graph in layers, first we look for all the neighbours of 
 * a node, keep track of the parent of a particular node, and store the nodes in a queue
 * then, we backtrack from the end node and store the path as the shortest path 
 * It is used to calculate the shortest path **/
#include <bits/stdc++.h>
using namespace std;

// this function does the actual bfs, visits every node that is connected from start
// it returns array of the parent of nodes

vector<int> solve(vector<vector<int>> &adj, int start, int n)
{
    queue<int> q;
    q.push(start);
    vector<bool> visited(n, false);
    visited[start] = true;

    vector<int> prev(n, -1);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        vector<int> neighbour = adj[node];
        for (auto next : neighbour)
        {
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
                prev[next] = node;
            }
        }
    }

    return prev;
}

// this function takes the parent array of the nodes, and checks if there exists a path
// between start and the end node and returns that path

vector<int> reconstructPath(int start, int end, vector<int> prev)
{
    vector<int> path;
    for (int x = end; x != -1; x = prev[x])
        path.push_back(x);

    reverse(path.begin(), path.end());

    if (path[0] == start)
        return path;

    return {};
}

vector<int> bfs(vector<vector<int>> &adj, int start, int end, int n)
{

    vector<int> prev = solve(adj, start, n);
    return reconstructPath(start, end, prev);
}

int main()
{
    int n, e;
    cout << "Enter no. of nodes and edges ";
    n = 13, e = 15;
    cout << "\nEnter the map ";
    vector<vector<int>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y), adj[y].push_back(x);
    }

    int start, end;
    cout << "\nEnter start node and end node ";
    cin >> start >> end;

    cout << "\nShortest path between " << start << " and " << end << " \n";
    vector<int> path = bfs(adj, start, end, n);
    if (path.size() > 0)
    {
        for (auto x : path)
            cout << x << " ";
        cout << endl;
    }
    else
        cout << "\nNo path\n";
}