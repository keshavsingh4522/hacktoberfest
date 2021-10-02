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
Node *findM(Node *head)
{
    if(head == nullptr || head!=nullptr)
    {
        return head;
    }
    Node *f=head, *s=head;
    while(f->next != nullptr && f->next->next !=nullptr)
    {
        s=s->next;
        f=f->next->next;
    }
    return s;
}

Node *Reverse(Node *head)
{
    if(head==nullptr||head->next==nullptr)
    {
        return head;
    }

    Node *k=Reverse(head->next);
    Node *t=head->next;
    t->next=head;
    head->next=nullptr;
    return k;
}

bool Palindrome(Node *head)
{
    if(head == NULL || head->next == nullptr)
    {
        return head;
    }
    Node *mid=findM(head);
    Node *nh=mid->next;
    // cout<<mid->data<<" "<<mid->next->data;
    mid->next=nullptr;
    nh=Reverse(nh);
    Node *i=head,*j=nh;
    bool flag=true;
    while(i != nullptr && j!=nullptr)
    {
        if(i->data != j->data)
        {
            flag=false;
            break;
        }
        i=i->next;
        j=j->next;
    }

        nh=Reverse(nh);
        mid->next=nh;

    return flag;
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

    if(Palindrome(head))
    {
        cout<<"The LL is Palindromic";
    }
    else
    {
        cout<<"The LL is not Palindromic";
    } 

    return 0;
}