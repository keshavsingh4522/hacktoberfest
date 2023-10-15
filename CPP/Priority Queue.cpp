#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    {
        priority_queue<int> q;
        for(int elm: {1,8,5,6,3,4})
            q.push(elm);
        while(!q.empty()){
            cout<<q.top()<<" ";
            q.pop();
        }
        cout<<endl;
    }
    {
        priority_queue<int, vector<int>, greater<int>> q2;
        for(int elm: {1,8,5,6,3,4})
            q2.push(elm);
        while(!q2.empty()){
            cout<<q2.top()<<" ";
            q2.pop();
        }
        cout<<endl;
    }
    {
        auto cmp=[] (int left, int right) { return(left) < (right);};
        priority_queue<int, vector<int>, decltype(cmp)> q3(cmp);
        for(int elm: {1,8,5,6,3,4})
            q3.push(elm);
        while(!q3.empty()){
            cout<<q3.top()<<" ";
            q3.pop();
        }
        cout<<endl;
    }
}
