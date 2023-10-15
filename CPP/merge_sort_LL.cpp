#include <bits/stdc++.h>
using namespace std;
 
struct node
{
    int data;
    struct node* next;
};
struct node *head=NULL;

struct node *SortedMerge(struct node *a,struct node *b){
    	struct node *result=NULL;
        struct node *temp;

        if(a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
        }
        if(a&&b){
            if(a->data <= b->data){
                temp=a;
                a=temp->next;
            }
            else{
                temp=b;
                b=temp->next;
            }
        }
        result=temp;
        while(a&&b){
            if(a->data <= b->data){
                temp->next=a;
                temp=a;
                a=temp->next;
            }
            else{
                temp->next=b;
                temp=b;
                b=temp->next;
            }
        }
        if(a==NULL)
            temp->next=b;
        if(b==NULL)
            temp->next=a;

        return result;
}

void FrontBackSplit(struct node *head,struct node **a,struct node**b){
    struct node *fast;
    struct node *slow;

    if(head==NULL||head->next==NULL){
        *a=head;
        *b=NULL;
    }
    else{
        slow=head;
        fast=head->next;

        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
        }
        *a=head;
        *b=slow->next;
        slow->next=NULL;
    }
}
void mergeSort(struct node** headRef){
    struct node* head=*headRef;
    struct node *a;
    struct node *b;

    //Base Case -- length 0 or 1
    if((head==NULL)||(head->next==NULL)){
        return;
    }

    FrontBackSplit(head,&a,&b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef=SortedMerge(a,b);
}


void displayLLD(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void insertAtBegin(int value){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    if(head==NULL){
        head=temp;
        temp->next=NULL;
        return;
    }
    temp->next=head;
    head=temp;
}

int main(){
    int n;
    cin>>n;

    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        insertAtBegin(x);
    }
    printf("Linked List\n");
    displayLLD(head);
    mergeSort(&head);
    printf("Merge Sorted Linked List\n");
    displayLLD(head);
}