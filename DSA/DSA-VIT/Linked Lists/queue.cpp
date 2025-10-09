#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
	int n;
	list<int>l;

	Queue()
	{
		n=0;
	}

	bool isEmpty()
	{
		return n==0;
	}

	void push(int data)
	{
		l.push_back(data);
		n++;
	}

	void pop()
	{
		if(!isEmpty())
		{
			n--;
			l.pop_front();
		}
	}

	int front()
	{
		return l.front();
	}
};

int main()
{
	Queue q;

	for(int i=0;i<6;i++)
		q.push(i);

	while(!q.isEmpty())
	{
		cout<<q.front()<<endl;
		q.pop();
	}
	return 0;
}