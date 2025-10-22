#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

bool check_pal(struct node* head_ref){
    struct node* curr=head_ref;
    stack<int>  s;

    while(curr!=NULL){
        s.push(curr->data);
        curr=curr->next;
    }
    while(head_ref!=NULL){
        int i=s.top();
        s.pop();
        if(head_ref->data!=i){
            return false;
        }
        head_ref=head_ref->next;
    }
    return true;
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
    push(&head,5);
    push(&head,7);
    push(&head,9);
    push(&head,2);
    push(&head,2);
    push(&head,9);
    push(&head,7);
    push(&head,5);
    cout<<check_pal(head);

}