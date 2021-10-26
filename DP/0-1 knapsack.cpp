//0-1 Knapsack problem with recursion and memiozation
   
#include<bits/stdc++.h>
using namespace std;

    int dp[101][1001];
    memset(dp,-1,sizeof(dp));

    int knapSack(int W, int wt[], int val[], int n) 
    { 
       if (n==0 || W==0) return 0;
       
    // memoization
       if (dp[n][w]!=-1) return dp[n][w];
       
    // if weight of the item in array is less than the max weight then we have 2 choice either include it or exclude it
    
       if (wt[n-1]<=W) {
           return dp[n][w] =max(val[n-1] + knapSack(W-wt[n-1],wt,val,n-1), knapSack(W,wt,val,n-1));
       }
       
    // if weight of item is more than max weight then we have to exclude it 
    
       else if (wt[n-1] >W) {
           return dp[n][w] = knapSack(W,wt,val,n-1);
       }
    }

int main() {
    n = 3
    W = 4
    val[] = {1,2,3}
    wt[] = {4,5,1}
    cout<< knapSack(W, wt, val, n)<<endl;
}
