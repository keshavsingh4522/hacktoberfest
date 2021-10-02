#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

// SC: O(n^2)
int CoinChange1(vector<int> &v, int sum){
	int n = v.size();

	int dp[n+1][sum+1]={0};

	for(int i=0; i<sum+1; i++)
		dp[0][i] = 0;
	for(int i=0; i<n+1; i++)
		dp[i][0] = 1;

	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(v[i-1] <= j)
				dp[i][j] = dp[i-1][j] + dp[i][j-v[i-1]];
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	return dp[n][sum];
}

// SC: O(n)
int CoinChange2(vector<int> &v, int sum){
	int n = v.size();

	int dp[sum+1] = {0};
	dp[0] = 1;

	for(int i=1; i<n+1; i++){
		for(int j=v[i-1]; j<sum+1; j++){
			dp[j] += dp[j-v[i-1]];
		}
	}

	return dp[sum];
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	vector<int> v = {1,2,3};
	int sum = 5;

	v = {2,5,3,6};
	sum = 10;

	cout<<CoinChange1(v, sum)<<endl;
	cout<<CoinChange2(v, sum)<<endl;
}