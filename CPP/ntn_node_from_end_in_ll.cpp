#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

int findNthnodefromEnd(struct node* head_ref,int n){
   struct node* main=head_ref;
   struct node* ref=head_ref;

    if(head_ref==NULL){
        return 0;
    }

    int count=0;
    while(count!=n-1){
        ref=ref->next;
        count=count+1;
    }
    while (ref->next!=NULL)
    {
        ref=ref->next;
        main=main->next;
    }
    return main->data;
    
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
    int n;
    cin>>n;
    struct node* head=NULL;
    push(&head,20);
    push(&head,29);
    push(&head,30);
    push(&head,52);
    push(&head,68);

    print(head);
    int x=findNthnodefromEnd(head,n);
    printf("%d",x);

}