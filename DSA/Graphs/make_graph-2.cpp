//weighted graphs using hashmap

#include <bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<string,list<pair<string,int>>>l;

   public:
    void addEdges(string x, string y,int val)
    {
        l[x].push_back(make_pair(y,val));
        l[y].push_back(make_pair(x,val));
    }

    void print()
    {
        //iterate over all the keys in the hash map
        for(auto x:l)
        {
            string city=x.first;
            list<pair<string,int>>nbrs=x.second;

            cout<<city<<"->";

            for(auto nbr:nbrs)
            {
                string dest=nbr.first;
                int dist=nbr.second;
                cout<<dest<<","<<dist<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph g;
    g.addEdges("A","B",10);
    g.addEdges("B","C",20);
    g.addEdges("C","A",30);

    g.print();
}
