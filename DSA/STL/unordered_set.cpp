#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    unordered_set<string>s;

    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
       s.insert(str);
    }

    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
         if(s.find(str)==s.end())
    cout<<"no";
    else
    cout<<"yes";

    }
  
}