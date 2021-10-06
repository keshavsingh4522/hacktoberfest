//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 22 in 18 : 20 : 33
//title - F_Potion.cpp
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator>
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
// #include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec "<<endl;
#define deb(x) cout<<endl<<"["<<#x<<" = "<<x<<"]"<<endl;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=1e2+10;
const int inf = /*0x3f3f3f3f*/3e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, a[N], x, dp[N][N][N], cost = inf;
void f(int k){
	rep(i, 0, n)
		rep(j, 0, n)
			rep(k, 0, n)
				dp[i][j][k] = - inf;
	dp[0][0][0] = 0;
	rep(i, 1, n)
		rep(koita, 1, k)
			//koita implies koita chosen
			rep(sum, 0, k - 1){
				dp[i][koita][sum] = max(dp[i - 1][koita][sum], dp[i - 1][koita - 1][(sum - a[i] + (inf / k) * k) % k] != - inf ? (dp[i - 1][koita - 1][(sum - a[i] + (inf / k) * k) % k] + a[i]) : - inf);
			}
	if(dp[n][k][x % k] == - inf)return;
	cost = min(cost, (x - dp[n][k][x % k]) / k);
}
void solve(){
	cin >> n >> x;
	rep(i, 1, n)
		cin >> a[i];
	rep(v, 1, n)
		f(v);
	cout << cost;

}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}