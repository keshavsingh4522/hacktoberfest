#include<bits/stdc++.h>
using namespace std;
class node // class
{
    public:
    int data;
    node* next;
};  
void print(node* head) // print linklist
{
    node* temp = head;
    while(temp)
    {
        cout<<temp -> data<<" --> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}
node* reverse(node* head) // reverse linked list
{
    if(!head || !head->next)
    {
        return head;
    }
    node* temp = reverse(head->next);
    node* tail = head->next;
    tail->next = head;
    head->next = NULL;
    return temp;
}
int main()
{
    node* n1 = new node();
    cout<<"enter the node data: ";
    cin>>n1 -> data;
    node* head = n1;
    node* tail = n1;
    char ch;
    cout<<"do you want to enter new node y/n: ";
    cin>>ch;
    while(ch=='y') // create linklist
    {
        node* n = new node();
        cout<<"enter the node data: ";
        cin>>n-> data;
        tail-> next = n;
        tail = n;
        cout<<"do you want to enter new node y/n: ";
        cin>>ch;
    }
    print(head);
    cout<<"do you want to insert any node in between: (y/n) ";
    cin>>ch;
    while(ch=='y') // enter at any index in linklist
    {
        int i;
        cout<<"at what position, please specify the index: ";
        cin>>i;
        int check=1;
        node* temp = head;
        if(i==0)
        {
            node* n = new node();
            cout<<"enter node data: ";
            cin>>n->data;
            n->next = temp;
            head = n;
            print(head);
            cout<<"do you want to insert any node in between: (y/n) ";
            cin>>ch;
        }
        else
        {
            while(temp)
            {
                if(check==i)
                break;
                check++;
                temp = temp->next;
            }
            node *pos = temp->next;
            node* n = new node();
            cout<<"enter node data: ";
            cin>>n->data;
            temp->next = n;
            n->next = pos;
            print(head);
            cout<<"do you want to insert any node in between: (y/n) ";
            cin>>ch;
        }
    }
    cout<<"do you want to reverse the linked list: (y/n) ";
    cin>>ch;
    while(ch=='y')
    {
        node* rev = reverse(head);
        print(rev);
        cout<<"do you want to reverse the linked list: (y/n) ";
        cin>>ch;
        head = rev;
    }
    return 0;
}
