#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> coins={1,2,5};
	int amount=9,n=coins.size();
	int dp[n][amount+1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=amount;j++)
		{
			if(j==0)
				dp[i][j]=0;
			if(i==0)
				dp[i][j]=j/coins[i];
			else if(coins[i]>j)
				dp[i][j]=dp[i-1][j];
			else
			{
				dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i]]);
			}
		}
	}
	cout<<dp[n-1][amount];
	return 0;
}
