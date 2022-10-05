#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *nxt;
};

void traverse(Node *n){
    while(n!=NULL){
        cout<<n->data<<endl;
        n=n->nxt;
    }
}

Node* create(){
int choice,d1,n;
Node *head=new Node();
Node *p=head;
cout<<"No. of elements to be entered : ";
cin>>n;
n--;
cout<<"Enter data : ";
cin>>d1;
head->data=d1;
while(n--){
    int data1;
    Node *q=new Node ();
    q->nxt=NULL;
    p->nxt=q;
    cout<<"enter data :";
    cin>>data1;
    q->data=data1;
    p=q;
}
return head;
}

void insert(Node* &n){
    int choice,data2;
    Node *q=n;
    Node *r;
    Node *p=new Node();
    cout<<"enter data for insertion : ";
    cin>>data2;
    p->data=data2;
    cout<<"Insert at => "<<endl<<"1. Front"<<endl<<"2. Middle"<<endl<<"3. End"<<endl<<"Enter choice : ";
    cin>>choice;
    if(choice==1){
        p->nxt=n;
        n=p;
    }
    else if(choice==2){
      int con;
      cout<<"Enter value after which data to be inserted : ";
      cin>>con;
      while(q->data!=con){
        q=q->nxt;
      }
     r=q->nxt;
     q->nxt=p;
     p->nxt=r;
    }
    else if(choice==3){
        while(q->nxt!=NULL){
            q=q->nxt;
        }
        q->nxt=p;
    }
    else{
        cout<<"Incorrect option chosen "<<endl;
    }
} 

void deletion(Node* &n){
int choice;
Node *p=n;
Node *q;
cout<<"1.Front "<<endl<<"2.Middle"<<endl<<"3.tail"<<endl<<"Enter choice : ";
cin>>choice;
if(choice==1){
    n=n->nxt;
    free(p);
}
else if(choice==2){
int data3;
cout<<"data to be deleted : ";
cin>>data3;
p=p->nxt;
q=n;
while(p->data!=data3){
     p=p->nxt;
     q=q->nxt;
    }
    Node *r=q;
    p=p->nxt;
    r=r->nxt;
    q->nxt=p;
    free(r);
}
else if(choice==3){
    p=p->nxt;
    q=n;
    while(p->nxt!=NULL){
     p=p->nxt;
     q=q->nxt;
    }
    q->nxt=NULL;
    free(p);
}
else cout<<"Wrong input";
}

int main(){
    Node *head;
    head=create();
    traverse(head);
    insert(head);
    traverse(head);
    deletion(head);
    traverse(head);
}