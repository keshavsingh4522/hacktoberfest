//Articulation Point and Bridges
void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED) { // a tree edge
            dfs_parent[v.first] = u;
            if (u == dfsRoot) rootChildren++; // special case if u is a root
            articulationPointAndBridge(v.first);
            if (dfs_low[v.first] >= dfs_num[u] && u!=dfsRoot) // for articulation point
                articulation_vertex[u] = true; // store this information first
            if (dfs_low[v.first] > dfs_num[u]) // for bridge
                printf(" Edge (%d, %d) is a bridge\n", u, v.first);
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]); // update dfs_low[u]
        }
        else if (v.first != dfs_parent[u]) // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]); // update dfs_low[u]
} }
// inside int main()
    dfsNumberCounter = 0; dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0);
    dfs_parent.assign(V, 0); articulation_vertex.assign(V, 0);
    printf("Bridges:\n");
    for (int i = 0; i < V; i++)
        if (dfs_num[i] == UNVISITED) {
            dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
            articulation_vertex[dfsRoot] = (rootChildren > 1); } // special case
    printf("Articulation Points:\n");
    for (int i = 0; i < V; i++)
        if (articulation_vertex[i])
            printf(" Vertex %d\n", i);