/*
Author:       Misbahud Din
Topic:      First In First Out (FIFO)
Description: Pushing Values to an Empty Array and then poping out those values
*/

#include <iostream>

using namespace std;

class FIFO				// Parent Class
{
protected:			
	int st[5] = {};		// An Empty Array
	int top;
	int tail;
public:
	FIFO(): top(-1), tail(-1)
	{
		// No arg constructor
	}
	void push(int var)		// Pushing values
	{
		cout << "Push = " << var << endl; 
		st[++top] = var;
	}
	int pop()				// Take number off Queue
	{
		return st[++tail];	// Returns the deleted integer
	}
};

class FIFO2 : public FIFO		// Child Class
{
public:
	FIFO2() : FIFO()
	{
		// No Arg Constructor of Parent Class
	}

	void push (int var)
	{
		if (top == 4)		// If stack gets full top = size - 1
		{
			cout << "Fifo is Full" << endl;
		}
		else
		{
			// Calling Parent's function
			FIFO::push(var);
		}
	}
	int pop ()
	{
		if ( top == tail)	// When top and tail gets equal it means the stack is empty 
		{
			cout << "Fifo is Empty" << endl;
			top = -1;		// Setting both values to -1 to use later
			tail = -1;
			return -1;
		}
		else
		{
			// Calling Parent's Function
			FIFO::pop();
		}
	}
};


int main()
{
	FIFO2 f;
	// Pushing 6 values 
	f.push(11);
	f.push(22);
	f.push(33);
	f.push(44);
	f.push(55);
	f.push(66);			// Full Condition
	// Poping values 
	cout << f.pop() << endl;	
	cout << f.pop() << endl;	
	cout << f.pop() << endl;	
	cout << f.pop() << endl;	
	cout << f.pop() << endl;	
	cout << f.pop() << endl;	// Empty array

	f.push(88);	
	f.push(99);

	cout << f.pop() << endl;	
	cout << f.pop() << endl;
		
	return 0;
}
