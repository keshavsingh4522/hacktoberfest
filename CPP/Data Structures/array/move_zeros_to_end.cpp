#include<bits/stdc++.h>
using namespace std;

void naive(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            for(int j=i;j<n;j++)
            {
                if(a[j]!=0)
                swap(a[i],a[j]);

            }
        }
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<endl;

}
void optimised(int a[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        count++;
        swap(a[count],a[i]);
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<endl;

}
int main()
{
    int a[6]={12,0,3,0,45,0};
    int n=sizeof(a)/sizeof(a[0]);
    //naive(a,n);
    optimised(a,n);
}
