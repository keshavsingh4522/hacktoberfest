#include <iostream>
#include <climits>
using namespace std;

/*3 options:
1) n/3
2) n/2
3) n--
*/

int minSteps(int n,int dp[])
{
	int op1,op2,op3;
	op1=op2=op3=INT_MAX;

	if(n==1)
		return 0;

	if(dp[n]!=0)
		return dp[n];

	//first case
	if(n%3==0)
		op1=minSteps(n/3,dp);

	//second case
	if(n%2==0)
		op2=minSteps(n/2,dp);

	//third case
	op3=minSteps(n-1,dp);

	int ans;
	ans=min(min(op1,op2),op3)+1;

	return dp[n]=ans;
}

int main()
{
	int n;
	cin>>n;

	int dp[100]={0};

	cout<<minSteps(n,dp);
	
	return 0;
}