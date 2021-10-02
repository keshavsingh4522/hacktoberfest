#include <iostream>
using namespace std;

//recursive solution
// int fib(int n)
// {
// 	int ans;
// 	if(n<=1)
// 		return n;

// 	return ans=fib(n-1)+fib(n-2); //recurrence relation
// }

// int main()
// {
// 	/* code */

// 	int n;
// 	cin>>n;

// 	cout<<fib(n);

// 	return 0;
// }


//DP approach
int fib(int n,int dp[])
{
	if(n<=1)
		return n;

	if(dp[n]!=0)
		return dp[n];

	int ans;
	ans=fib(n-1,dp)+fib(n-2,dp);
	return dp[n]=ans;
}

int main()
{
	int n;
	cin>>n;

	int dp[100]={0};
	cout<<fib(n,dp);

	return 0;
}