
#include<iostream>
#include<cstring>
using namespace std;

int editDistance(string s1, string s2){
    int m=s1.length();
    int n=s2.length();
    
    int **dp=new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        dp[i]=new int[n+1];
    }
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=i;
    }
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[m-i]==s2[n-j])
                dp[i][j]=dp[i-1][j-1];
            else
            {
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
            }
        }
    }
    return dp[m][n];
}

int main(){
	string s1, s2;
	cout<<"Enter first string - ";
	cin>>s1;
	cout<<"Enter second string - ";
	cin>>s2;
	cout<<"Edit Distance is - "<<editDistance(s1, s2)<<endl;
}
