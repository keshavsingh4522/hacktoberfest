#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(5);

    cout<<s.top();
    cout<<"\n";
    s.pop();
    cout<<s.top();
    return 0;
}  