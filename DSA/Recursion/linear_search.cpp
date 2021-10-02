#include <iostream>
using namespace std;

int search(int *a,int n,int key)
{
    if(n==0)
    return -1;

    //key present at 1st index of an array
    if(a[0]==key)
    return 0;
    
    int i=search(a+1,n-1,key);
    if(i==-1)
    return -1;

    return i+1;
}

int main() {
   int n,i;
   cin>>n;
   int arr[n];
   for(i=0;i<n;i++)
   cin>>arr[i];

   int key;
   cin>>key;

   cout<<search(arr,n,key);
}