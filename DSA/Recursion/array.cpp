#include <iostream>
using namespace std;

bool sort(int a[],int n)
{
    if(n==0 || n==1)
    return true;
    if(a[0]<a[1] && sort(a+1,n-1))
    return true;
    return false;
}

int main() {
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   cin>>arr[i];

   cout<<sort(arr,n);
}

