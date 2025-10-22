#include<bits/stdc++.h>
using namespace std;
int lcmfn(int a, int b)
{
    int res=max(a,b);
    while(1)
    {
        if(res%a==0 && res%b==0)
        return res;
        else
        res++;
    }
    return res;
}
int main()
{
    int a=4 ,b=6;
    cout<<lcmfn(a,b);
}