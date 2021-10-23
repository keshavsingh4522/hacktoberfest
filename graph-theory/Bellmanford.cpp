// This algorithm is used in cases when the weight of edges can be negative. and there are negative cycles present
// in the graph. ( even if the graph is acyclic then also due to negative weights dijsktra fails.)

// so we use Bellman ford in order to know where the negative cycles are and also get the least value for other parts.

// bellman ford has a complexity of O(EV) which is much more than dijsktra's so use it wisely.


#include<iostream>
#include<vector>
#include<limits>
#include<map>
using namespace std;

class Edge{
    public:
        int from;
        int to;
        int cost;

        Edge(int from,int to,int cost){
            from = from;
            to = to;
            cost = cost;
    }
};

void bellman(vector<Edge>&edges,vector<double>&distance,int start){
    // computing the minimum distance between all the edges.
    distance[start] = 0;
    for(auto i:distance){
        for(Edge edge:edges){
            distance[edge.to] = min(distance[edge.to],distance[edge.from]+ edge.cost);
        }
    }

    // Detecting negative cycles if the distance again comes out to be less it means there was a negative cycle. for that case set distance to infinity.
    for(auto i:distance){
        for(Edge edge:edges){
            if(distance[edge.to]>distance[edge.from]+edge.cost){
                distance[edge.to] = numeric_limits<float>::infinity();
            }
        }
    }
    return;
}

int main(){
    int v;
    int e;
    vector<double>distance(v,numeric_limits<float>::infinity());
    int u,v,w;
    vector<Edge>edges(e);
    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        edges[i] = Edge(u,v,w);
    }
    int start;
    cin>>start;
    bellman(edges,distance,start);
    for(auto x:distance){
        cout<<x<<" ";
    }
}