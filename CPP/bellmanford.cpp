#include<bits/stdc++.h>
using namespace std;
int main()
{
	int v,e;
	cin>>v>>e;
	vector< pair<int,int> > adj[v];
	for(int i=0;i<e;i++)
	{
		int src,dest,w;
		cin>>src>>dest>>w;
		adj[src].push_back({dest,w});
	}
	int src;
	cin>>src;
	int dist[v];
	for(int i=0;i<v;i++)dist[i]=INT_MAX;
	dist[src]=0;
	for(int i=0;i<(v-1);i++)
	{
		for(int j=0;j<v;j++)
		{
			for(int k=0;k<adj[j].size();k++)
			{
				int s,d,w;
				s = j;
				d = adj[j][k].first;
				w =  adj[j][k].second;
				if(dist[d]>(dist[s]+w) && dist[s]!=INT_MAX)
				{
					dist[d] = dist[s] + w;
				}
			}
		}
	}
	bool x=true;
	for(int j=0;j<v;j++)
	{
		for(int k=0;k<adj[j].size();k++)
		{
			int s,d,w;
			s = j;
			d = adj[j][k].first;
			w =  adj[j][k].second;
			if(dist[d]>dist[s]+w && dist[s]!=INT_MAX)
			{
				x = false;
			}
		}
	}
	for(int i=0;i<v;i++)cout<<dist[i]<<' ';
	cout<<endl;
}