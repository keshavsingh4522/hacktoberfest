#include<bits/stdc++.h>
using namespace std;
int gcdfn(int a, int b)
{
    int res=min(a,b);
    while(res>0)
    {
        if(a%res==0 && b%res==0)
        break;
        res--;
    }
    return res;
}
int main()
{
    int a=200 , b=100;
    cout<<gcdfn(a,b);
}