#include<bits/stdc++.h>
using namespace std;

void remove_duplicate(int a[],int n)
{
    int current=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[current])
        a[current]=a[i];
        current=i;
        
    }
    for(int i=0;i<n;i++)
    cout<<a[i];
}
int main()
{
    int a[5]={1,1,2,2,3};
    int n=5;
    remove_duplicate(a,n);
}