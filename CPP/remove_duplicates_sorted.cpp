#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void sort(struct node* head_ref){
    struct node* curr=head_ref;
    while(curr!=NULL){
        if(curr->data==curr->next->data){
            curr->next=curr->next->next;
        }
        curr=curr->next;
    }
}

void push(struct node** head_ref,int num){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=(*head_ref);
    *head_ref=newnode;
}

void print(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    struct node* head=NULL;
    push(&head,68);
    push(&head,68);
    push(&head,42);
    push(&head,42);
    push(&head,20);
    push(&head,20);

    print(head);
    sort(head);
    print(head);

}