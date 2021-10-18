// this is another method of finding the shortest path as there are many methods we will study quite a lot of them 
// and find out which suits us best. 
// we cannot use negative values in dijstra's algorithm.

//The code written below is the lazy version of dijkstra's algorithm and we can make it better by using an indexed 

// in order to store the value and obtain the shortest path as well. Use a prev[] array or vector which stores the
// predicessor and then finally gets upto the start point when reversed.
 
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

void add_edge(vector<pair<int,int>>adj[],int u,int v,int w){
    pair<int,int>p =  make_pair(v,w);
    adj[u].push_back(p);
    return;
}

void shortestpath(vector<int>&prev,int end){
    if(prev[end]==-1){
        cout<<"no path exists"<<endl;
    }
    else{
        int i=end;
        vector<int>path;
        path.push_back(i);
        while(prev[i]!=-1){
            path.push_back(prev[i]);
            i=prev[i];
        }
        for(auto i=path.end()-1;i>=path.begin();i--){
            cout<<*i<<" ";
        }
        cout<<endl;
    }
    return;
}

void dijkstra(vector<pair<int,int>>adj[],int nodes[],unordered_map<int,int>storage,vector<int>prev){
    while(storage.size()!=0){
        int index;
        int distance = INT32_MAX;
        for(auto i=storage.begin();i!=storage.end();i++){
            if(i->second<distance){
                index = i->first;
                distance = i->second;
            }
        }

        for(auto i:adj[index]){
            if(storage[i.first]!=0)
            nodes[i.first] = min(storage[i.first],min(nodes[i.first],i.second + nodes[index]));
            else
            nodes[i.first] = min(nodes[i.first],i.second + nodes[index]);
            
            if(storage[i.first]!=nodes[i.first])
            prev[i.first]=index;

            storage[i.first] = nodes[i.first];
            // cout<<storage[i.first]<<" ";
        }
        storage.erase(index);
    }
    int end;
    cin>>end;
    cout<<nodes[end]<<endl;
    shortestpath(prev,end);
    return;
}

int main(){
    int n;
    cin>>n;
    int nodes[n];
    vector<int>prev(n,-1);
    unordered_map<int,int>storage;
    for(int i=0;i<n;i++){
        nodes[i] = INT32_MAX;
    }
    vector<pair<int,int>>adj[n];
    int k;
    cin>>k;
    int u,v,w;
    for(int i=0;i<k;i++){
        cin>>u>>v>>w;
        add_edge(adj,u,v,w);
    }
    int start;
    cin>>start;
    storage[start] = 0;
    nodes[start] = 0;
  
    dijkstra(adj,nodes,storage,prev);
    // for(auto i:nodes){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    return 0;
}