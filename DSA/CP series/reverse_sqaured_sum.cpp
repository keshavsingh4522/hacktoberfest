#include <bits/stdc++.h>
using namespace std;
int main() {
   
   int n;
   cin>>n;

   int a[n];
   for(int i=0;i<n;i++)
   cin>>a[i];

   int sum=0;
   bool flag=true;

   for(int i=n-1;i>=0;i--)
    {
        if(flag==true)
        sum+=a[i]*a[i];
        else
        sum-=a[i]*a[i];

        flag=!flag;
    }

    cout<<sum;
}
