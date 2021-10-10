#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define fo(i,a,b) for(int i=a ; i<b ; i++)
#define foe(i,a,b) for(int i=a ; i<=b ; i++)
#define endl '\n'
#define ff first
#define ss second
#define MOD 1000000007
ll vis[100][100];
ll n,m;
bool isValid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m)
    return false;
    if(vis[x][y]==1)
    return false;
    else
    return true;

}
void dfs(ll x,ll y)
{
    vis[x][y]=1;
    if(isValid(x-1,y))
    dfs(x-1,y);
    if(isValid(x,y+1))
    dfs(x,y+1);
    if(isValid(x+1,y))
    dfs(x+1,y);
    if(isValid(x,y-1))
    dfs(x,y-1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    // cin>>t;
    // t=1;
    while(t--)
    {
       ll ar[1001][1001];
        cin>>n>>m;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            cin>>ar[i][j];
        }
        //connected components
        // ll cc=0;
        //  for(ll i=1;i<=n;i++)
        // {
        //     for(ll j=1;j<=m;j++)
        //     {
        //         if(ar[i][j]==1 && vis[i][j]==0)
        //         dfs(i,j);
        //     }
        // }
        dfs(1,1);
    }
    
    return 0;
}