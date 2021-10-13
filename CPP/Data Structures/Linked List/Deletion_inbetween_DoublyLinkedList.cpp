//DELETION OF DLL ELEMENT IN BETWEEN
//Enter the data as input to delete the DLL 
#include <iostream>
using namespace std;
struct node{
    int data;
    node *ptr,*pre;
};
node *head=NULL;
void insertathead(int a){
    node *p=new node;
    p->data=a;
    p->pre=p->ptr=NULL;
    if(head==NULL){
        head=p;
    }
    else{
        head->pre=p;
        p->ptr=head;
        head=p;
    }
}
void deleteinbetween(int a){
    node *p=head;
    while(p && p->data!=a){
        p=p->ptr;
    }
    if(p->ptr==NULL)
        cout<<"NOT FOUND";
    else{
        p->pre->ptr=p->ptr;
        p->ptr->pre=p->pre;
    }
    p=NULL;
}
void displayfromhead(){
    node *p=head;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->ptr;
    }
}
int main(){
    insertathead(40);
    insertathead(30);
    insertathead(20);
    insertathead(10);
    insertathead(5);
    cout<<"BEFORE DELETION\n";
    displayfromhead();
    deleteinbetween(30);
    cout<<"AFTER DELETION in between\n";
    displayfromhead();
    return 0;
  
}
