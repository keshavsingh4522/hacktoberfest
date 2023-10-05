#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    // initialize as DisjointSet ds(7);
    // ds.unionByRank(1,2); or  ds.unionBySize(1,2);
    // ds.findUPar(2);
    private:
        vector<int> rank,size,parent;
    public:
        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++) parent[i]=i;
        }
        int findUPar(int node)
        {
            if(node==parent[node]) return node;
            return parent[node]=findUPar(parent[node]);
        }
        void unionByRank(int u,int v)
        {
            int pu=findUPar(u);
            int pv=findUPar(v);
            if(pu==pv) return;
            if(rank[pu]<rank[pv]) parent[pu]=pv;
            else if(rank[pv]<rank[pu]) parent[pv]=pu;
            else {parent[pv]=pu;rank[pu]++;}
        }
        void unionBySize(int u,int v)
        {
            int pu=findUPar(u);
            int pv=findUPar(v);
            if(pu==pv) return;
            if(size[pu]<size[pv]) {parent[pu]=pv;size[pv]+=size[pu];}
            else {parent[pv]=pu;size[pu]+=size[pv];}
        }
};

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(3,4);
    ds.unionBySize(5,6);
    ds.unionBySize(5,7);
    for(int i=1;i<=7;i++)
    {
        cout<<"Parent of vertex "<<i<<" :"<<ds.findUPar(i)<<endl;
    }
}