// Problem Statement:  Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if the length of the rod is 8 and the values of different pieces are given as the following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 
// This problem is solved using Top - Down approach of dynamic programming
#include<iostream>
int price[]={1, 5, 8, 9, 10, 17, 17, 20},length=8,dp[1000][1000];
using namespace std;
int solve(int n,int sum,int used){  //n=current length level , used=used length
    if (n<=0)
    {
        return sum;
    }
    if (n<=(length-used))
    {
        dp[n][used]=max(solve(n,sum+price[n-1],used+n),solve(n-1,sum,used));
        return dp[n][used];
    }
    else
    {
        dp[n][used]=solve(n-1,sum,used);
        return dp[n][used];
    }
}
int main(){
    int n=sizeof(price)/sizeof(price[0]);
    cout<<solve(n,0,0);
}
