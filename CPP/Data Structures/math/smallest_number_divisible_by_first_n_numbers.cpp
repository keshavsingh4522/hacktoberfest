#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long ans=1;
    long long n;
    cout<<"enter the number n:";
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        ans=(ans*i)/__gcd(ans,i);
    }
    cout<<ans;
    
    
}