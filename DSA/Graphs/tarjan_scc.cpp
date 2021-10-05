/** A strongly connected component of a graph is a subgraph 
 * such that all vertices of the subgraph are connected to each other, 
 * means we can reach every other vertices in the subgraph from any vertices **/

/** Tarjan's SCC algorithm uses stack to keep track of the nodes while we are visiting
 * such that all the nodes of which we have explored the neighbours, we will first push
 * them in the stack and when it is completed, we pop them one by one **/

/** We will also use the concept of low-link values, while giving the nodes initially
 * id == low_link, if the current has a low-link value equal to id, then it can be
 * the start of a SCC, but we can't be sure **/

#include <bits/stdc++.h>
using namespace std;

const int UNVISITED = -1;
int id = 0;     // to give the nodes unique id
int cntSCC = 0; // no. of SCCs

int n = 8; // no. of nodes in the graph

vector<int> ids(8, 0);
vector<int> low_link(8, 0);
vector<bool> onStack(8, 0); // to keep track of which element is currently on stack

stack<int> st;

void dfs(int at, vector<vector<int>> adj)
{
    // add the current node to the stack
    st.push(at);
    onStack[at] = true;

    // first give ids == low link value
    ids[at] = low_link[at] = id++;

    for (auto to : adj[at])
    {
        if (ids[to] == UNVISITED)
            dfs(to, adj);

        // if the current element is on the stack, we update the low link
        // value
        if (onStack[to])
            low_link[at] = min(low_link[to], low_link[at]);

        // we have visited all the neighbour of the current node
        // now we will see if lowlink of current equals id, and pop off the stack

        if (ids[at] == low_link[at])
        {
            while (!st.empty())
            {
                int node = st.top();
                st.pop();

                // remove the curr node from stack
                onStack[node] = false;
                low_link[node] = ids[at];

                if (node == at)
                    break;
            }
            cntSCC++;
        }
    }
}

void findSCC(vector<vector<int>> adj)
{
    for (int i = 0; i < n; i++)
        ids[i] = UNVISITED;

    for (int i = 0; i < n; i++)
    {
        if (ids[i] == UNVISITED)
            dfs(i, adj);
    }
}

// all the nodes which have ids == low_Link, will now be in a strongly connected comp

int main()
{
    int e;
    cout << "Enter no. nodes and edges ";
    cin >> e;

    cout << "\nEnter the graph\n";

    vector<vector<int>> adj(8);
    for (int i = 0; i < e; i++)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    findSCC(adj);
    cout << "No. of strongly connected components are ";
    cout << cntSCC << endl;
}