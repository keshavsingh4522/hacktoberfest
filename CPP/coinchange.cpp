#include<iostream>

using namespace std;
int dp[100];
int minCoins(int coins[],int target,int n)
{
    //base case
    if(target == 0)
        return 0;
    if(dp[target] != 0 )
        return dp[target];
    int ans = INT16_MAX;
    for(int i=0;i<n;i++)
    {
        if(target-coins[i] >= 0)
        {
            int subproblem = minCoins(coins,target-coins[i],n);
            ans = min(ans,subproblem+1);
        }
    }
    dp[target] = ans;
    return dp[target];
}

int main()
{
    int coins[] = {1,7,10};
    int val = 15;
    
    for(int i=0;i<100;i++)
    {
        dp[i] = 0;
    }
    cout << minCoins(coins,val,3) << endl;
    return 0;
}

