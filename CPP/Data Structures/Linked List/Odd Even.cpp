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
        cout<<k->data<<" - >  ";
        k=k->next;
    }
    return;
}

Node *sep(Node *head)
{
    if(head==NULL || head->next == NULL)
    {
        return head;
    }

    Node *DE=new Node(-1);
    Node *DO=new Node(-1);
    Node *et=DE, *ot=DO, *curr=head;
    while(curr!=nullptr)
    {
        if( (curr->data) %2 == 0)
        {
            et->next=curr;
           et=et->next;
        }
        else
        {
            ot->next=curr;
            ot=ot->next;
        }

        curr=curr->next;
    }

    ot->next=nullptr;
    et->next=DO->next;
    return DE->next;
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
    cout<<endl;
    head=sep(head);
    disp(head);
    return 0;
}