#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *sort(struct node* head_ref){
   struct node* main=head_ref;
    int n0=0;
    int n1=0;
    int n2=0;

    while(main !=NULL){
        if(main->data==0){
            n0++;
        }
        if(main->data==1){
            n1++;
        }
        if(main->data==2){
            n2++;
        }
        main=main->next;
    }
    main=head_ref;
    while(n0!=0){
        main->data=0;
        main=main->next;
        n0--;
    }
    while(n1!=0){
        main->data=1;
        main=main->next;
        n1--;
    }
    while(n2!=0){
        main->data=2;
        main=main->next;
        n2--;
    }

    return head_ref;
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
    push(&head,2);
    push(&head,2);
    push(&head,2);
    
    print(head);
    sort(head);
    print(head);

}