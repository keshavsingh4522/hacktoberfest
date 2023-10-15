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

Node* Ibeg(Node *head, int x)
{
    Node *temp=new Node(x);
    if(head==nullptr)
    {
        return temp;
    }
    
    Node *curr=head;
    head=temp;
    head->next=curr;
    return head;
}

Node *Imiddle(Node *head, int x, int pos)
{
    Node *temp=new Node(x);
    Node *curr=head;
    if(pos==1)
    {
        temp->next=head;
        return temp;
    }
    for(int i=1; i<=pos-2 && curr!=nullptr; i++)// goes till that node where changes happen
    {
        curr=curr->next;
    }
    if(curr==nullptr)
    {
        return head;
    }
    temp->next=curr->next;
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
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int k;
        cin>>k;
        head=Ibeg(head,k);
    }

    disp(head);
    int l,pos;
    cin>>l>>pos; 
    head=Imiddle(head,l,pos);

    disp(head);

    return 0;

}