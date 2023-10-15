#include <bits/stdc++.h>
using namespace std;

class Stack{
    private:
    vector<int>v;
    public:
    void push(int data)
    {
        v.push_back(data);
    }
    void pop()
    {
        if(!empty())
        v.pop_back();
    }
    int top()
    {
        return v[v.size()-1];
    }
    bool empty()
    {
        return (v.size()==0);
    }
};

int main() {
    Stack s;

    //pushing elements into stack
    for(int i=0;i<=5;i++)
    {
        s.push(i*i);
    }

    //popping elements from stack
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}

