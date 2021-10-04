#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insertattail(node* &head, int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
node* reverse(node* head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;

}
node* addonetolinked(node* head){
    node* res=head;
    node* temp;
    node* prev=NULL;
    int carry=1,sum;
    while(head!=NULL){
        sum=carry + head->data;
        carry=(sum>=0)?1:0;
        sum=sum%10;
        temp=head;
        head=head->next;
        
    }
    if(carry>0){
        temp->next=new node(carry);
    }
    return res;
}

node* addone(node* head){
    head=reverse(head);
    head=addonetolinked(head);
    return reverse(head);
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;

    }
    cout<<endl;
}

int main(){
    node* head=NULL;
    insertattail(head,1);
    insertattail(head,9);
    insertattail(head,9);
    insertattail(head,9);
    display(head);
    head=addone(head);
    display(head);
  
}