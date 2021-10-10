#include<bits/stdc++.h>
using namespace std;

int gcdfn(int a, int b)
{
    int res =min(a,b);
    while(res >0)
    {
        if(b==0)
        return a;
        else
        return gcdfn(b,a%b);
    }
    return a;

}
int lcmfn(int a, int b)
{
    return (a*b)/gcdfn(a,b);
}
int main()
{
    int a=3, b=5;
    cout<<lcmfn(a,b);
}