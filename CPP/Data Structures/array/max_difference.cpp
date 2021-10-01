// array given 
// find the max sum i.e a[j]-a[i]= max 
// such that j>i

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[8]={1,2,3,4,54,513,23,2};
    int diff=a[1]-a[0];
    int mini=a[0];
    for(int i=1;i<8;i++)
    {
         diff=max(diff,a[i]-mini);
         mini=min(mini,a[i]);
    }
    cout<<diff;

}




















