#include <bits/stdc++.h>
using namespace std;
int main() {

    //declaration
    vector<int>v;
    vector<int>v1(5,1);//5 elements having value 1
    vector<int>v2={1,2,3,4,5};

    //printing vectors
    for(int i=0;i<v2.size();i++)
    cout<<v2[i];
    cout<<endl;

    for(auto x:v2)
    cout<<x;
    cout<<endl;

    for(auto it=v2.begin();it!=v2.end();it++)
    cout<<*it;
    cout<<endl;

    //user input
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        v.push_back(no);
    }
    cout<<endl;

    //insert elements
    v.push_back(1);
    v.insert(v.begin(),5); //(pos,val)

    //remove elements
    v.pop_back();
    v.erase(v.begin(),v.begin()+1);
    v.clear();
}

