#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    set<string>s;

    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
       s.insert(str);
    }

    for(auto x:s)
    cout<<x<<" ";

}