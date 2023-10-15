#include<iostream>
#include <cstring>
#include <climits>
using namespace std;
long int size[1000];
long int price[1000];
long long dp[1001][1001];
int knapsack(int n,int c){
	//base case
	if(n==0 || c==0){
		return 0;
	}
	//look up
	if(dp[n][c]!=-1){
		return dp[n][c];
	}
	//rec case
	int op1,op2;
	op1=op2=INT_MIN;
    if(c>=size[n-1]){
        op1=price[n-1]+knapsack(n-1,c-size[n-1]); //including the nth item
    }
	op2=knapsack(n-1,c); //excluding the nth item
	dp[n][c]=max(op1,op2);
    return dp[n][c];
}

int main() {
	int n,s;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>size[i];
	}
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
    memset(dp,-1,sizeof dp);
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	}
	for(int j=0;j<=s;j++){
		dp[0][j]=0;
	}
	cout<<knapsack(n,s)<<endl;
	return 0;
}