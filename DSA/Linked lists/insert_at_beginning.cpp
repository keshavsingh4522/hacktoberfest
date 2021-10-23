#include <bits/stdc++.h>
using namespace std;

class node{
   public:
     int data;
     node *next;
     node(int val){
        data=val;
        next=NULL;
     }
};
void insertAtTail(node *&head,int val){
   node *n=new node(val);
   if(head==NULL){
      head=n;
      return;
   }
    node *temp=head;
    while(temp->next!=NULL){
       temp=temp->next;
    }
    temp->next=n;
}
//Insert at begining
void insertathead(node *&head,int val){
       node *n=new node(val);
       n->next=head;
       head=n;
}
void display(node *head){
   node *temp=head;
   while(temp!=NULL){
      cout<<temp->data<<" ";
      temp=temp->next;
   }
      cout<<endl;
}
int main(){
    node *head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
     display(head);
     insertathead(head,12);
     display(head);
}
/*
Output
1 2 3
12 1 2 3
*/
