// this algorithm takes O(V^3) time as well as O(V^2) memory. but unlike other algorithms it computes 
// the shortest path from any node to any other node which makes it the APSP .(all pairs shortest path).
// whereas other algorithm's done uptil now are all SSSP.(for a fixed start value). use it only for very short graphs


#include<iostream>
#include<limits>
#include<vector>
using namespace std;

int shortestpath(double ** dp,int **next , int start,int end){
// function to return the shortest path and -1 if there is no path exists.
    vector<int>path;
    if(next[start][end]==-1)
    return -1;
    else{
        for(int i=start;i!=end;i=next[i][end]){
            if(i==-1)
            return -1;
            path.push_back(i);
        }
    }
    path.push_back(end);
    for(auto x:path){
        cout<<x<<" ";
    }
    return 0;
}

void floyd(double** adj_mat,double **dp,int v){
    int**next = new int*[v];
    for(int i=0;i<v;i++){
        next[i] = new int[v];
    }
    // creating the next array to help find the shortest distance between all points. 
    // next[i][j] stores the next destination.
    // e.g if A -> B -> C is a path and A -> C is another path.
    // then if distance A->B->C  is less than next[A][B] =  C 
    // initially as there is only 1 path so next[A][B] = B
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(dp[i][j]==numeric_limits<float>::infinity())
            next[i][j] = -1;
            else
            next[i][j] = j;
        }
    }
    // calculating the minimum possible distance among all the paths possible.
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(dp[i][j]>dp[i][k] + dp[k][j]){
                    dp[i][j] = dp[i][k] + dp[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    // marking those paths which are not possible.
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(dp[i][j]>dp[i][k] + dp[k][j]){
                    dp[i][j] = numeric_limits<float>::infinity();
                    next[i][j] = -1;
                }
            }
        }
    }

    int start;
    int end;
    int k = shortestpath(dp,next,start,end);
    if(k==-1)
    cout<<"no path exists"<<endl;
    return;
}

// 
int main(){
    // initializing variables and array to store distances.
    int v;
    cin>>v;
    double**adj_mat = new double*[v];
    double** dp = new double*[v];
    for(int i=0;i<v;i++){
        adj_mat[i] = new double[v];
        dp[i] = new double[v];
    }
    // setting the distance between i th and j th position to infinity as they are not yet connected. and 0 for i==j.
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(i!=j)
            adj_mat[i][j] = numeric_limits<float>::infinity();
            else
            adj_mat[i][j] = 0;
            dp[i][j] = adj_mat[i][j];
        }
    }
    int u,v,w;
    while(cin>>u>>v>>w){
        adj_mat[u][v] = w;
        dp[u][v] = adj_mat[u][v];
    }

    floyd(adj_mat,dp,v);
    return 0;
}