#include<bits/stdc++.h>
using namespace std;

int main(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(4);
    q.push(6);
    cout<<q.front()<<" "<<q.back()<<endl;
    q.pop();
    cout<<q.front()<<" "<<q.back()<<endl;
}