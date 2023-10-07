#include<iostream>
using namespace std;
int A[100];
int front = -1;
int rear = -1;
bool isFull()
{
bool b = false;
if(rear==99)
   {  b = true;  }
   else
   {  b = false;  }
return b;
}
bool isEmpty()
{
   bool b = false;
   if(front==-1 && rear==-1)
   {  b = true;  }
   else
    {  b = false;  }
   return b;
}
void Enqueue()
{
  int a;
  bool full = isFull();
  bool empty = isEmpty();
  if(full==true)
{  cout<<"\nQueue is FULL!\n";  }
else if(empty==true)
{  cout<< "Enter Value you want to Enqueue: ";
    cin>> a;
   front = 0;
   rear = 0;
   A[rear] = a;
   cout<< a<< " has been Enqueued to Rear of Queue.\n";
}
else
{  cout<< "Enter value you want to Enqueue: ";
    cin>> a;
    rear++;
    A[rear] = a;
    cout<< a<< " has been Enqueued to Rear of Queue.\n";
}
cout<< endl;
}
void Dequeue()
{  bool empty = isEmpty();
   if(empty==true)
   {  cout<< "\nQueue is Empty!\n";  }
  else if (front==rear)
   {  front = -1;
      rear = -1;
     cout<< "Element from Front Dequeued.\n";
  }
  else
  {  front++; 
       cout<< "Element from Front Dequeued.\n";
}
cout<< endl;
}
void Display()
{
   bool empty = isEmpty();
   if(empty==true)
    {  cout<< "Queue Empty!";  }
  else
{  cout<< "Queue: ";
   for(int i=front; i<=rear; i++)
    {  cout<< A[i]<< " ";  }
}
cout<< endl;
}
int main()
{
   int ch;
   cout<< "-----------------------Array implementation of Queue---------------------------\n";
   cout<< "\t1. Enqueue an element to Queue\n";
   cout<< "\t2. Dequeue an element to Queue\n";
   cout<< "\t3. Display all elements of Queue\n";
   cout<< "\t4. Exit\n";
   cout<< "-------------------------------------------------------------------------------\n";
   while(ch!=4)
   {
     cout<< "\nEnter your choice: ";
     cin>> ch;
      if(ch==1)
     {  Enqueue();  }
     else if(ch==2)
     {  Dequeue();  }
    else if(ch==3)
     {  Display();  }
     }
     if(ch==4)
     {  cout<< "Exit System..\n";  }
      system("pause");
       return 0;  
}
