// question--https://cses.fi/problemset/task/1617/
#include<iostream>
#include<vector>
using namespace std;
#define mod ((int)1e9 + 7)
int bit_st(long long n,int i)
{
    if(i==n) return 1;
    int k=bit_st(n,i+1);
    if (k>mod)  k=k%mod;
    return  2*k;
}
int main()
{
    long long n;
    cin>>n;
    int k =bit_st(n,0);
    if (k>mod) 
      k=k%mod;
    cout<<k; 
    return 0;
}
