#include <bits/stdc++.h>
using namespace std;

int * topoSort(vector<int> graph[], int N)
{
   int indegree[N];
   memset(indegree, 0, sizeof indegree);
   int* topo = new int[N+1];
   
   for(int j = 0;j<N;++j){
       vector<int>:: iterator i;
       for(i = graph[j].begin();i!=graph[j].end();++i){
           indegree[*i]++;
       }
   }
   queue<int> q;
   for(int i=0;i<N;++i){
       if(indegree[i] == 0) q.push(i);
   }
   int k = 0;
   while(!q.empty()){
       int top = q.front();
       q.pop();
       topo[k++] = top;
       vector<int>:: iterator i;
       for(i = graph[top].begin();i!=graph[top].end();++i){
           indegree[*i]--;
           if(indegree[*i] == 0) q.push(*i);
       }
   }
   return topo;
}

int main() {
    
}
