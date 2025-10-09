#include<bits/stdc++.h>
using namespace std;
int find(int s, int parent[])
{
	if(parent[s]==-1)return s;
	else return find(parent[s], parent);
}

void Union(int x,int y,int parent[])
{
	int a = find(x,parent);
	int b = find(y,parent);
	if(a==b)return;
	else 
	{
		parent[a]=b;
	}
}
void addedge(int u,int v,vector<int> adj[])
{

	adj[u].push_back(v);
}
bool findcycle(vector<int> adj[],int v )
{
	int parent[v];
	for(int i=0;i<v;i++)parent[i]=-1;
	for(int i=0;i<v;i++)
	{
		int p = find(i,parent);
		int siz = adj[i].size();
		for(int j=adj[i][0];i<=adj[i][siz-1];j++)
		{
			int c = find(adj[i][j],parent);
			if(c==p)return true;
			Union(p,c,parent);
		}
		
	}
	return false;

}

int main()
{
	int v=4;
	vector<int> adj[4];
	addedge(0,1,adj);
	addedge(1,2,adj);
	addedge(0,2,adj);
	addedge(2,3,adj);
	addedge(2,0,adj);
	if(findcycle(adj,4))cout<<"yes"<<endl;
	else cout<<"No"<<endl;

}