//queue using only 2 stacks
#include <bits/stdc++.h>
using namespace std;

class Queue{
    private:
    stack<int>s1,s2;

    public:
    void push(int data)
    {
        s1.push(data);
    }
    void pop()
    {
        // pop n-1 elements from s1 to s2 and pop last element from s1 to queue and then interchange s1,s2
        while(s1.size()>1)
        {
            int element=s1.top();
            s2.push(element);
            s1.pop();
        }
        //popping last element
        s1.pop();
        swap(s1,s2);
    }
    int front()
    {
        while(s1.size()>1)
        {
            int element=s1.top();
            s2.push(element);
            s1.pop();
        }
        int element=s1.top();
        s1.pop();
        s2.push(element);
        return element;
    }
    int size()
    {
        return (s1.size()+s2.size());
    }
    bool empty()
    {
        return size()==0;
    }
};

int main() {
    queue<int>q;

    for(int i=0;i<=3;i++)
    q.push(i);

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}

