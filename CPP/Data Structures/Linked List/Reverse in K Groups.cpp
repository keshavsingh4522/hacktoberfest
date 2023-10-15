#include<bits/stdc++.h>
using namespace std; 

struct Node 
{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

Node* Iend(Node *head,int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
    return temp;
    Node *curr=head;
    while(curr->next!=nullptr)
    {
        curr=curr->next;
    }
    curr->next=temp;
    return head;

}

void disp(Node* head)
{
    Node* k=head;
    if(head == nullptr)
    {
        cout<<"The LL is Empty";
        return;
    }
    while(k!=nullptr)
    {
        cout<<k->data<<" -> ";
        k=k->next;
    }
    return;
}

Node* Rev(Node *head, int k)
{
    Node*curr=head;
    Node* prev=nullptr,*next=nullptr;
    int count=0;
    while(curr!=nullptr && count< k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++; 
    }
     if(next!=nullptr)
     {
         Node *rh=Rev(next,k);
         head->next=rh;
     }
    return prev;
}


int main()
{
     int n;
    cin>>n;
    Node* head=NULL;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        head=Iend(head,k);
    }

    //disp(head);
    int k;
    cin>>k;
    head=Rev(head,k);
    cout<<endl;
    disp(head);
    return 0;

}