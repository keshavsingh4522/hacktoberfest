#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cin>>key;

    bool present=binary_search(arr,arr+n,key);
    if(present)
    cout<<"present";
    else
    cout<<"absent";
}

