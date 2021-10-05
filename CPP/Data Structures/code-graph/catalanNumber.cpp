/*
c(n) = summation [C(i) * C(n-i)]
C(0) = 1;
C(1) = 1;
C(2) = C(0)*C(1) + C(1)*C(0) = 2;
C(3) = C(0)*C(2) + C(1)*C(1) + C(2)*C(0) = 5;
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int catalan(int n)
{
    if(n<=1)
    {
        return 1;
    }

    int res=0;
    for(int i=0;i<n;i++)
    {
        res += catalan(i)*catalan(n-i-1);
    }
    return res;
}

int main()
{
    for(int i=0;i<10;i++)
    {
        cout<<catalan(i)<<" ";
    }
    cout<<endl;

    return 0;
}