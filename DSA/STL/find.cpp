#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cin>>key;

    auto it=find(arr,arr+n,key);
    int index=it-arr;
    cout<<index;
}

