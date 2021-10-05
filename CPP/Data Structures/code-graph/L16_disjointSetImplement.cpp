#include <bits/stdc++.h>
using namespace std;

int parent[100000];
int rank_[100000];

void makeSet()
{
    for (int i = 1; i <= 100000; i++)
    {
        parent[i] = i;
        rank_[i] = 0;
    }
}
int findPar(int node)
{
    if (node == parent[node])
        return node;
    // LHS(parent[node]=) saves it so that path compression occurs
    return parent[node]=findPar(parent[node]);
}
void union_(int u,int v)
{
    u=findPar(u);
    v=findPar(v);

    if(rank_[u]<rank_[v])
    {
        parent[u]=v;
    }
    else if(rank_[u]>rank_[v])
    {
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank_[u]++;
    }
}

int main()
{
    makeSet();
    int m;
    cin>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        union_(u,v);
    }
    // Check if a and b are in same component
    int a,b;
    cin>>a>>b;
    if(findPar(a)!=findPar(b))
        cout<<"Different component"<<endl;
    else
        cout<<"Same Component"<<endl;
    return 0;
}

/*
* Input1:-
3
1 2
3 4
4 5
a=3 b=5

* Output1:-
Same Component

*Input2:-
3
1 2
3 4
4 5
a=2 b=5

*output2:-
Different component


*/