#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    //cin>>key;

    rotate(arr,arr+n/2,arr+n);

    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

