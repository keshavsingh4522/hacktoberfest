//using list

#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;

    //pointer list of vertices
    list<int>*l;
    public:
    Graph(int v)
    {
        this->v=v;
        l=new list<int>[v];
    }

    void addEdges(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void print()
    {
        for(int i=0;i<v;i++)
        {
            cout<<"vertex "<<i<<"->";
            for(auto x:l[i])
            cout<<x<<", ";
            cout<<endl;
        }
    }
};

int main() {
    Graph g(3);
    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(2,0);

    g.print();
}
