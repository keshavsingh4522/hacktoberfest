#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    cin>>a[i];

    vector<int>left(n,0);
    vector<int>right(n,0);
    left[0]=a[0];
    right[n-1]=a[n-1];

    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1],a[i]);
        right[n-i-1]=max(right[n-i],a[n-i-1]);
    }

}

 //calc height of water
    int height=0;
    for(int i=1;i<n;i++)
    height+=min(left[i],right[i])-v[i];
    cout<<height;