#include <bits/stdc++.h>
using namespace std;
void make_set(vector<int> &parent)
{
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }
}
int find(vector<int> &parent, int y)
{
    if (parent[y] != y)
    {
        parent[y] = find(parent, parent[parent[y]]);
    }
    return parent[y];
}
void union_set(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int root1 = find(parent, x);
    int root2 = find(parent, y);
    if (root1 == root2)
        return;
    if (rank[root1] > rank[root2])
    {
        parent[root2] = root1;
    }
    else
    {
        parent[root1] = root2;
        if (rank[root1] == rank[root2])
        {
            rank[root2]++;
        }
    }
}
bool iscyclic(vector<pair<int, int>> &v, int size)
{
    vector<int> parent(size);
    vector<int> rank(size, 0);
    make_set(parent);
    for (auto x = v.begin(); x != v.end(); x++)
    {
        int root1 = find(parent, x->first);
        int root2 = find(parent, x->second);
        if (root1 == root2)
        {
            return true;
        }
        else
            union_set(parent, rank, root1, root2);
    }
    return false;
}
int main()
{
    int size = 6;
    vector<pair<int, int>> v;
    v.push_back(make_pair(0, 1));
    v.push_back(make_pair(0, 2));
    v.push_back(make_pair(1, 3));
    v.push_back(make_pair(2, 3));
    v.push_back(make_pair(3, 4));
    v.push_back(make_pair(4, 5));
    cout<<  iscyclic(v, size);

    return 0;
}