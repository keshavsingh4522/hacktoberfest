#include <bits/stdc++.h>
using namespace std;
int main() {
    unordered_map<string,int>m;
    int n;
    cin>>n;
    string str;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        m[str]++;
    }

    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout<<m[str]<<endl;
    }
}