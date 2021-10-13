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

void deleteAthead(node *&head){
   node *todelete=head;
   head=head->next;
     delete todelete;
}
 void deletion(node *&head,int val){
    //If no node is present
      if(head==NULL){
         return;
      }
      //If only one node is present
      if(head->next==NULL){
         deleteAthead(head);
      }
        node *temp=head;
         while(temp->next->data!=val){
            temp=temp->next;
         }
         node *todelete=temp->next;
         temp->next=temp->next->next;
         delete todelete;
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
    deletion(head,2);
    display(head);
     deleteAthead(head);
     display(head);
}
/* Output
1 2 3
1 3
3
*/
