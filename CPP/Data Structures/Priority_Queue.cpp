#include<bits/stdc++.h>
//Global declaration for queue implementation using unordered single array
#define MAX_SIZE 1000
int Queue[MAX_SIZE];
int i=0;
using namespace std;
//Global declaration for queue implementation using ordered linked list
class Node{
   public:
       int priority;
       int data;
       Node* next;

};
Node* front=NULL;

//Global declaration for queue implementation  using multiple arrays .
//2D ARRAY coresponds to multiple queues having different priority.
int Q[MAX_SIZE][MAX_SIZE];
int Front[MAX_SIZE];
int Rear[MAX_SIZE];




//PRIORITY QUEUE IMPLEMENTATION USING UNORDERED SINGLE ARRAY
//Value assigned to elements of queue corresponds to its priority.
// Insert an item at the rear of the queue in O(1)
void Enqueue_using_array(int item) {
        // Check if the queue is full
        if (i==MAX_SIZE-1) {
              cout<<"Error:Queue is full\n";
                return;
        }
        Queue[i++] = item;
}
/* Removes the item with the maximum priority
 search the maximum item in the array and replace it with
the last item ,In worst case time complexity approaches
to o(n).*/

int Dequeue_using_array()
{
    int item;
        // Check if the queue is empty
        if (i == 0) {
                cout<<"ERROR:Queue is empty\n";
                return -999999;
        }
        int j, maxi = 0;
        // find the maximum priority
        for (j = 1; j < i; j++) {
                if (Queue[maxi] < Queue[j]) {
                        maxi = j;
                }
        }
        item = Queue[maxi];

        // replace the max with the last element
        Queue[maxi] = Queue[i - 1];
        i = i - 1;
        return item;

}
void Display_using_array(int Queue[],int i)
{
  cout<<"The priority queue at this stage is as follows:-\n";
    for(int j=0;j<i;j++)
    {
        cout<<Queue[j]<<" ";
    }
    cout<<"\n";
}



//PRIORITY QUEUE IMPLEMENETATION USING ORDERED LINKED LIST
//Enqueue operation takes O(n) time in worst case.
void Enqueue_using_linkedlist(int x,int priority)
{   Node* q;
    Node* temp=new Node();
    temp->data=x;
    temp->priority=priority;
    temp->next=NULL;
    /*Queue is empty or item to be added has priority more than first item*/
    if(front==NULL || priority<front->priority)
    {
        temp->next=front;
        front=temp;
    }
    else{

        q=front;
        while(q->next!=NULL && q->next->priority<=priority)
        {
            q=q->next;
        }
        temp->next=q->next;
        q->next=temp;
    }

}
//Dequeue operation takes O(1) time complexity.
void Dequeue_using_linkedlist()
{
    Node* temp=front;
    if(front==NULL)
    {
        cout<<"Already empty cannot pop elements from it"<<"\n";
        return;
    }
    else{
        cout<<"Deleted item is "<<temp->data<<"\n";
        cout<<"Its priority being "<<temp->priority<<"\n";
        front=front->next;
        delete(temp);
    }

}
void Display_using_linkedlist()
{
    Node* temp=front;
    if(front==NULL)
    {
        cout<<"Queue is empty\n";
    }
    else
    {  cout<<"The priority queue at this stage is as follows:-\n";
        while(temp!=NULL)
        {
            cout<<"Data stored is:- "<<temp->data<<"  Its priority is:-"<<temp->priority<<"\n";
            temp=temp->next;
        }
    }

}


//PRIORITY QUEUE USING MULTIPLE ARRAYS.
//Enqueue operation takes O(n^2) time in worst case.
void Enqueue_using_multiplearrays(int x,int priority)
{
    for(int i=0;i<MAX_SIZE;i++)
    {
        if(i==priority)
        {
            if((Rear[i]+1)%MAX_SIZE==Front[i])
           {
             cout<<"Cannot enter more no"<<"\n";
              return;
            }
            else if(Rear[i]==-1 && Front[i]==-1)
              {
                  Front[i]=0;
                  Rear[i]=0;
                  Q[i][Rear[i]]=x;
              }
              else{
                  Rear[i]=(Rear[i]+1)%MAX_SIZE;
                  Q[i][Rear[i]]=x;
              }
        }
    }
}
//Dequeue operation takes O(1) in average case.
void Dequeue_using_multiplearrays()
{
    for(int i=0;i<MAX_SIZE;i++)
    {
        if(Front[i]!=-1 && Rear[i]!=-1)
        {
             cout<<"Deleted Element is "<<Q[i][Front[i]]<<"\n";
             cout<<"Its priority being:- "<<i<<"\n";
             Front[i]=(Front[i]+1)%MAX_SIZE;
             return;
        }
    }
    return;

}

void Display_using_multiplearrays()
{
    for(int i=0;i<MAX_SIZE;i++)
    {
        if(Front[i]!=-1 && Rear[i]!=-1)
        {
            cout<<"The queue with priority  "<<  i  <<"  is as follows"<<"\n";
      for(int j=0;j<(((Rear[i]-Front[i]+MAX_SIZE)%MAX_SIZE)+1);j++){
        cout<<Q[i][((Front[i]+j)%MAX_SIZE)]<<" ";
    }
     cout<<"\n";
        }
    }
}

void  PriorityQueuebyArray(int Queue[])
{   int count;
      cout<<"Enter the number of time you want to perform operation on queue\n";
      cin>>count;
      while(count>0)
      {
          int option;
          cout<<"1)Enter 1 for enqueue operation\n";
          cout<<"2)Enter 2 for dequeue operation\n";
          cout<<"3)Enter 3 for viewing status of priority queue\n";
          cin>>option;
          if(option==1)
          {   int x;
              cout<<"Enter the value to be enqueued\n";
              cin>>x;
              Enqueue_using_array(x);
              count--;
          }
          else if(option==2)
          {
             cout<<"Deleted element is"<<Dequeue_using_array()<<"\n";
             count--;
          }
          else if(option==3)
          {
              Display_using_array(Queue,i);
              count--;
          }
          else{
            cout<<"Kindly reenter your choice\n";
          }
      }
}

void PriorityQueuebyLinkedList()
{
      int count;
      cout<<"Enter the number of time you want to perform operation on queue\n";
      cin>>count;
       while(count>0)
      {
          int option;

          cout<<"1)Enter 1 for enqueue operation\n";
          cout<<"2)Enter 2 for dequeue operation\n";
          cout<<"3)Enter 3 for viewing status of priority queue\n";
          cin>>option;
          if(option==1)
          {   int x;
              int priority;
              cout<<"Enter the value to be enqueued\n";
              cin>>x;
              cout<<"Enter its priority\n";
              cin>>priority;
              Enqueue_using_linkedlist(x,priority);
              count--;
          }
          else if(option==2)
          {  Dequeue_using_linkedlist();
             cout<<"\n";
              count--;
          }
          else if(option==3)
          {   Display_using_linkedlist();
              count--;
          }
          else{
            cout<<"Kindly reenter your choice\n";
          }

      }
}

void PriorityQueuebyMultipleArray()
{
      int count;
      cout<<"Enter the number of time you want to perform operation on queue\n";
      cin>>count;
      for(int i=0;i<MAX_SIZE;i++)
     {
       Front[i]=-1;
       Rear[i]=-1;
      }
       while(count>0)
      {
          int option;
          cout<<"1)Enter 1 for enqueue operation\n";
          cout<<"2)Enter 2 for dequeue operation\n";
          cout<<"3)Enter 3 for viewing status of priority queue\n";
          cin>>option;
          if(option==1)
          {   int x;
              int priority;
              cout<<"Enter the value to be enqueued\n";
              cin>>x;
              cout<<"Enter its priority\n";
              cin>>priority;
              Enqueue_using_multiplearrays(x,priority);
              count--;
          }
          else if(option==2)
          {  Dequeue_using_multiplearrays();
             cout<<"\n";
              count--;
          }
          else if(option==3)
          {   Display_using_multiplearrays();
              count--;
          }
          else{
            cout<<"Kindly reenter your choice\n";
          }

      }

}

int main()
{
    int option;
    cout<<"Enter your option\n";
    cout<<"1)By using unordered array \n";
    cout<<"2)By using ordered linked list\n";
    cout<<"3)By using multiple arrays\n";
    cin>>option;
    if(option==1)
    {

       PriorityQueuebyArray(Queue);
    }
    else if(option==2)
    {
        PriorityQueuebyLinkedList();
    }
    else if(option==3)
    {
        PriorityQueuebyMultipleArray();
    }
    else
    {
        cout<<"Enter correct option\n";
    }
    return 0;
}
