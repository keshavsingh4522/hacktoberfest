#include<iostream>
using namespace std;
class queue{
	private:
	int *a;
	int front,rear,cs,ms;
	public:
		queue(int ds=5)//ds is the default size the user will give
		{
			// int a[ds]; u can't declare like this
            a=new int[ds]; //using DMA
			cs=0;
			ms=ds;
			front=0;
			rear=ms-1;
		}
		bool full()
		{
			if(ms==cs)
			{
				return true;
			}
			return false;
		}
		void push(int d)
		{
			if(!full())
			rear=(rear+1)%ms;  //for circular queue
			a[rear]=d;
			cs++;
			
		}
		bool empty()
		{
			if(cs==0)
			{
				return true;
			}
		 return false;
		}
		void pop()
		{
			if(!empty())
			{
				front=(front+1)%ms;
				cs--;
		     }
		}
		int f()
		{
			return a[front];
		}
		~queue()
		{
			if(a!=NULL)
			{
				delete [] a;
				a=NULL;
			}
		}
		
};
int main()
{
	queue q;
	int n;
	cin>>n;
	for(int i=0;i<5;i++)
	{
		q.push(i);
	}
    while(!q.empty())
    {
        cout<<q.f()<<" ";
        q.pop();
    }
    return 0;
}
