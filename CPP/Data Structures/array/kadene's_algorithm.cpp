#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>a={-2,1,-3,4,-1,2,1,-5,4};
    int max_current =a[0];
    int max_global=a[0];
    for(int i=1;i<a.size();i++)
    {
        max_current=max(a[i],a[i]+max_current);
        if(max_current>max_global)
        max_global=max_current;
    }
    cout<<max_global;
}