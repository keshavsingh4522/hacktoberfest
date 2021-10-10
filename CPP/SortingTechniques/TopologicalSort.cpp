#include<iostream>
#include<vector>
#include<algorithm>

/*
    The class accepts a directed graph in form of adjacency list and checks whether its
    topological sorts exits or not and produces its corresponding topological sort.

    Complexity: O(n)
*/

class TopologicalSort
{
    private:
    int n;
    bool exist;
    std::vector<int> sorted_v, visited, rank;
    std::vector<std::vector<int>> &graph;

    /* topological sorting */
    void topo(int par)
    {
        visited[par] = 1;
        for(int e: graph[par])
        {
            if(!visited[e]) topo(e);
        }
        sorted_v.push_back(par);
    }

    void generate_topological_sort()
    {
        sorted_v.assign(0, 0);
        visited.assign(n, 0);
        
        for(int i = 0;i < n; i++)
        {
            if(!visited[i]) topo(i);
        }

        std::reverse(sorted_v.begin(), sorted_v.end());

        check_existence();
    }

    void check_existence()
    {
        rank.assign(n, 0);
        for(int i =0 ;i < n; i++)
        {
            rank[sorted_v[i]] = i;
        }

        for(int i =0 ;i <n; i++)
        {
            for(int e: graph[i])
            {
                if(rank[i] > rank[e]) exist = false;
            }
        }
    }

    public:

    TopologicalSort(std::vector<std::vector<int>> &graph) : graph(graph), n((int)graph.size()), exist(true)
    {
        generate_topological_sort();
    }

    std::vector<int> get_sort()
    {
        return sorted_v;
    }

    bool is_valid()
    {
        return exist;
    }
};
