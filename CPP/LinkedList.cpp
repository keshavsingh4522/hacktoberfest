// INSERTING IN THE SEQUENCE ANYWHERE
#include <iostream>
using namespace std;
struct node{
    int data;
    node *ptr;
};
struct node *head=NULL;
void insert(int a){
    struct node *temp=new node;
    temp->data=a;
    temp->ptr=head;
    head=temp;
}
void display(){
    node *p=head;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->ptr;
    }
}
int main(){
    insert(45);
    insert(55);
    insert(65);
    insert(75);
    insert(05);

    node *add= new node;
    add->data=69;
    add->ptr=NULL;
    node *temp=head;
    while(temp!=NULL && temp->data!=65){
        temp=temp->ptr;
    }
    add->ptr=temp->ptr; 
    temp->ptr=add;
    display();
}
