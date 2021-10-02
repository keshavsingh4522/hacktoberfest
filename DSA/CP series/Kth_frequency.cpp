#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int a[n];

    for(int i=0;i<n;i++)
    cin>>a[i];

    unordered_map<int,int>m;
    vector<int>v;

    for(int i=0;i<n;i++)
    m[a[i]]++;

    for(auto x:m)
    {
        if(x.second>k)
        v.push_back(x.first);
    }
    if(v.empty())
    cout<<"-1";
    else
   for(auto x:v)
   cout<<x<<" ";
   cout<<endl;
}
