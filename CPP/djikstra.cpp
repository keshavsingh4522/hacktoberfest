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
	vector<bool> sptset;
	vector<int>dist;
	for(int i=0;i<v;i++)
	{
		dist.push_back(INT_MAX);
	}
	dist[src]=0;
	for(int i=0;i<v;i++)
	{
		sptset.push_back(false);
	}
	for(int count=0;count<(v-1);count++)
	{
		vector<int>:: iterator it = min_element(dist.begin(),dist.end());
		int idx = it - dist.begin();
		sptset[idx] = true;
		for(int i = 0;i<adj[idx].size();i++)
		{
			int v = (adj[idx][i]).first;
			int w = (adj[idx][i]).second;
			if((sptset[v]==false) && dist[v]>dist[idx]+w)
			{
				dist[v] = dist[idx] + w;
			}
		}
	}
	for(int i=0;i<v;i++)cout<<dist[i]<<' ';
		cout<<endl;
}