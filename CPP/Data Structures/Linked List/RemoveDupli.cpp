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
        cout<<k->data<<" ";
        k=k->next;
    }
    return;
}

Node *RemDupli(Node *head)
{
    if(head==NULL||head->next==nullptr)
    {
        return head;
    }

    Node* temp=head;
    for(Node *curr=head->next;curr!=nullptr;curr=curr->next)
    {
           if(curr->data==temp->data)
           {
                temp->next=curr->next;
           }
           else
           {
               temp=curr;
           }
    } 
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

    disp(head);

    RemDupli(head);

    cout<<endl;

    disp(head);

}