#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB emplace_back
typedef pair<int,int> pii;
const int MAX_N = 1e5+5;
const int INF = 1e9;
/*
    DP various knapsack AC
    k==-1 : infinity knapsack
    k== 1 : 0/1 knapsack
    k>  1 : bounded knapsack {
        k(10) decompose into binary(2) :
        Eg: 13 -> 1+2+4+ rest(6) (all fo these amount can be combine all permutation of amount )
    }

*/
ll dp[MAX_N]={};
int main(){
    OAO
    int n,Limit,wt,val,k;
    int Weight[MAX_N],Value[MAX_N],cnt=0;
    cin>>n>>Limit;
    while(n--){
        cin>>val>>wt>>k;
        if(k==-1){
            for(int w=wt;w<=Limit;w++){
                dp[w]=max(dp[w],dp[w-wt]+val);
            }
        }
        else if(k==1){
            for(int w=Limit;w-wt>=0;w--){
                dp[w]=max(dp[w],dp[w-wt]+val);
            }
        }
        else{
            int base=1,rest=k;
            while(rest>=base){
                Weight[++cnt]=wt*base;
                Value[cnt] =val*base;
                rest-=base;
                base*=2;
            }
            if(rest>0){
                Weight[++cnt]=wt*rest;
                Value[cnt] = val*rest;
            }
        }
    }

    for(int i=1;i<=cnt;i++){
        for(int w=Limit;w-Weight[i]>=0;w--){
            dp[w]=max(dp[w],dp[w-Weight[i]]+Value[i]);
        }
    }

    cout<<dp[Limit];
    return 0;
}
