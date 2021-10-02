#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<ll>>adj;
vector<ll>level;
const ll lg = 20;
const ll size = 1e5 + 2;
ll up[200005][21];

ll dfs(ll child, ll parent)
{
	
	up[child][0] = parent;
	
	for(int i=1; i<lg; i++)
	{
		up[child][i] = up[up[child][i-1]][i-1];
	}
	for(auto i:adj[child])
	{
		if(i != parent)
		{
			level[i] = level[child] + 1;
			dfs(i,child);
		}
	}
}

ll lift(ll x, ll y)
{
	for(int i=0; i<lg; i++)
	{
		if(1<<i & y)
		{
			x = up[x][i];
			y -= 1<<i;
		}	
	}	
	return x;
} 
 
ll lca(ll a, ll b)
{
	if(level[a] > level[b])
		swap(a,b);
	
	ll d = level[b] - level[a];
	
	while(d > 0)
	{
		ll i = log2l(d);
		b = up[b][i];
		d -= (1<<i);	
	}	
	if( a == b)
		return a;
	
	for(int i=20; i>=0; i--)
	{
		if(up[a][i] !=0 && (up[a][i] != up[b][i]))
		{
			a = up[a][i] , b = up[b][i];
		}
	}
	return up[a][0];
} 
 
 
 
 
 
 
 
ll solve()
{
	ll n,q;
	cin>>n>>q;
	adj.clear();
	adj.resize(n+4);
	level.clear();
	level.resize(n+4);
	for(int i=2; i<=n; i++)
	{
		ll u,v;
		cin>>u;
		v = i;
		adj[u].push_back(v);
		adj[v].push_back(u);
			
	}	
	dfs(1,0);
	
//	ll q;
	//cin>>q;
	while(q--)
	{
		ll a,b,c;
		cin>>a>>b;
		
		ll ans = lca(a,b);
	
		cout<<ans<<endl;
		
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
    ll ignore = 1;
    //cin>>ignore;
    while(ignore--)
    {
    	solve();
	}
}
