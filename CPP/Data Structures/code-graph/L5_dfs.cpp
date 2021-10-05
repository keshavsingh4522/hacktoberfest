#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<int> dfsGraph(int n, vector<int> arr[])
    {
        vector<int> dfs;
        vector<int> vis(n + 1, 0);
        stack<int> s;
        s.push(1);
        vis[1] = 1;

        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            dfs.push_back(node);

            for (auto it : arr[node])
            {
                if (!vis[it])
                {
                    s.push(it);
                    vis[it] = 1;
                }
            }
        }
        return dfs;
    }
};

int main()
{
    int m, n;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solution obj;
    vector<int> ans = obj.dfsGraph(n, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
        // cout << ans.size();
    }
    cout << endl;

    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
        storeDfs.push_back(node); 
        vis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, storeDfs); 
            }
        }
    }
public:
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    vector<int> storeDfs; 
	    vector<int> vis(V+1, 0); 
      for(int i = 1;i<=V;i++) {
        if(!vis[i]) dfs(i, vis, adj, storeDfs); 
      }
	    return storeDfs; 
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
*/