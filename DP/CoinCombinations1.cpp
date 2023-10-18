#include<bits/stdc++.h>
using namespace std;

const int mod = (int)1e9+7;

// Memoization
int coinCombinations1(int x, int ind , vector<int> &a, vector<vector<int>> &dp)
{
    if(x < 0)return 0;
    if(x == 0) return 1;

    if(dp[ind][x] != -1) return dp[ind][x];

    int ans = 0;
    for(int i = ind ; i < a.size(); ++i)
    {
        ans += coinCombinations1(x - a[i], i , a, dp);
        ans %= mod;

    } 

    return dp[ind][x] = ans;
}


int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n,0);
    for(auto &val : a){cin >> val;}
    // cout << coinCombinations1(x, 0, a, dp) << endl;      // calling function fof memo solution

    // iterative dp (Tabulation)
    int dp[x+1][n+1] = {0};
    for(int i = 0 ; i < n + 1; i++)
    {
        dp[0][i]= 1;
    }
   

    dp[0][0] = 1;
    
    for(int sum = 1; sum <= x; sum++)
    {
        for(int j = n-1 ; j >= 0; --j)
        {
            if(sum - a[j] >= 0)
            {
                dp[sum][j] += dp[sum - a[j]][j] ;
            }

            dp[sum][j] += dp[sum][j+1];
            dp[sum][j] %= mod;
        }
    }


    cout << dp[x][0] << endl;

    
}   