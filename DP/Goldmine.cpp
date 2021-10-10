#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;cin>>n>>m;
    int arr[n][m];

    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    } 
    
    int **dp;
    dp=new int*[n];
    for(int i=0;i<n;i++)
    dp[i]=new int[m];   
    for(int j=m-1;j>=0;j--)
    {
    for(int i=n-1;i>=0;i--) 
    { 
      if(j==m-1)
      {
        dp[i][j]=arr[i][j];
      } 
      else if(i==n-1)
      {
   dp[i][j]=arr[i][j]+max(dp[i][j+1],dp[i-1][j+1]);
      } 
      else if(i==0) 
      { 
  dp[i][j]=arr[i][j]+max(dp[i][j+1],dp[i+1][j+1]);
  
        } 
        else 
        {  
          
  dp[i][j]=arr[i][j]+max(dp[i][j+1],max(dp[i+1][j+1],dp[i-1][j+1]));
          
          } 
          } 
          } 
          
   int b=dp[0][0]; 
   for(int i=1;i<n;i++) 
   { 
     
      b =max(b,dp[i][0]);
     
     } 
     
     cout<<b<<endl; 
     }
