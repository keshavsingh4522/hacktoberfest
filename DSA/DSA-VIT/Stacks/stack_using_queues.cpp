//stack using only 2 queues
#include <bits/stdc++.h>
using namespace std;

class Stack{
    private:
    queue<int>q1,q2;

    public:
    void push(int data)
    {
        q1.push(data);
    }
    void pop()
    {
        // pop n-1 elements from q1 to q2 and pop last element from q1 to stack and then interchange q1,q2
        while(q1.size()>1)
        {
            int element=q1.front();
            q2.push(element);
            q1.pop();
        }
        //popping last element
        q1.pop();
        swap(q1,q2);
    }
    int top()
    {
        while(q1.size()>1)
        {
            int element=q1.front();
            q2.push(element);
            q1.pop();
        }
        int element=q1.front();
        q1.pop();
        q2.push(element);
        return element;
    }
    int size()
    {
        return (q1.size()+q2.size());
    }
    bool empty()
    {
        return size()==0;
    }
};

int main() {
    stack<int>s;

    for(int i=0;i<=3;i++)
    s.push(i);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

