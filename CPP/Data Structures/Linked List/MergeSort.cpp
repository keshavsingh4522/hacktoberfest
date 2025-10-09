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
        cout<<k->data<<" - > ";
        k=k->next;
    }
}

Node *MergeLL(Node *l1,Node *l2)
{
    if(l1==nullptr || l2==nullptr)
    {
        return l1 != nullptr?l1:l2;
    } 

    Node *d=new Node(-1);
    Node *c1=l1, *c2=l2, *p=d;
    while(c1!=nullptr && c2!=nullptr)
    {
        if(c1->data < c2->data)
        {
            p->next=c1;
            c1=c1->next;
        }
        else{
            p->next=c2;
            c2=c2->next;
        }
        p=p->next;
    }

    if(c1==nullptr)
    {
        p->next=c2;
    }
    else
    {
        p->next=c1;
    }

    return d->next;

}

Node *Mid(Node *head)
{
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }
     Node *f=head , *s=head;
     while(f->next && f->next->next)
    {
        f=f->next->next;
        s-s->next;
    }

    return s;
}

Node *mergesort(Node *head)
{
    if(head==nullptr || head->next==nullptr)
    {
        return head;
    }
    Node *mid=Mid(head);
    Node *nh=mid->next;
    mid->next=NULL;

    Node *l1=mergesort(head);
    Node *l2=mergesort(nh);

    return MergeLL(l1,l2); 
}

int main()
{
    int n;
    cin>>n;
    Node* head=NULL, *head1=NULL;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        head=Iend(head,k);
    }

    disp(head);
    cout<<endl;

    head=mergesort(head);
    disp(head);
    cout<<endl;
}
    
