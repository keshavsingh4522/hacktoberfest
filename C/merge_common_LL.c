#include <stdio.h>
#include <stdlib.h>

struct node
{   int data;
    struct node* next;
    struct node* prev;
};

struct node* head3=NULL;
struct node* head4=NULL;

void insert_l(struct node** head_r,int item)
{   struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=item;
    newNode->next=(*head_r);
    newNode->prev=NULL;
    if((*head_r)!=NULL)
        (*head_r)->prev=newNode;
    (*head_r)=newNode;
}

void insert_r(struct node** head_r,int item)
{   struct node* newNode=(struct node*)malloc(sizeof(struct node));
    struct node* last=(*head_r);
    newNode->data=item;
    newNode->next=NULL;
    if((*head_r)==NULL)
    {
        newNode->prev=NULL;
        (*head_r)=newNode;
        return;
    }
    while(last->next!=NULL)
        last=last->next;
    last->next=newNode;
    newNode->prev=last;
    return;
}

void merge(struct node* head_r1,struct node* head_r2)
{   struct node* t1=head_r1;
    struct node* t2;
    for(;t1!=NULL;t1=t1->next)
    {   int val=t1->data;
        int x=0;
        for(t2=head_r2;t2!=NULL;t2=t2->next)
        {   
            if(t2->data==val)
            {   insert_r(&head3,val);
                x=1; break;
            }
        }
        if(x==0)
        {   insert_r(&head4,t1->data);
        }
    }
    t1=head_r2;
    for(;t1!=NULL;t1=t1->next)
    {   int val=t1->data;
        int x=0;
        for(t2=head3;t2!=NULL;t2=t2->next)
        {   
            if(t2->data==val)
            {   x=1; break;
            }
        }
        if(x==0)
        {   insert_r(&head4,t1->data);
        }
    }
}

void printList(struct node* node)
{
    while(node!=NULL)
    {   printf("%d->",node->data);
        node=node->next;
    }
}

int main()
{   int ch,item;
    struct node* head1=NULL;
    struct node* head2=NULL;
    do{
        printf("\n1.INSERT_A");
        printf("\n2.INSERT_B");
        printf("\n3.MERGE A AND B");
        printf("\n4.EXIT");
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {   case 1: printf("\nEnter item:");
                    scanf("%d",&item);
                    insert_r(&head1,item);
                    printf("\nList A:\n");
                    printList(head1);
                    break;
            case 2: printf("\nEnter item:");
                    scanf("%d",&item);
                    insert_r(&head2,item);
                    printf("\nList B:\n");
                    printList(head2);
                    break;
            case 3: merge(head1,head2);
                    printf("\nList with common elements:\n");
                    printList(head3);
                    printf("\nList with non-common elements:\n");
                    printList(head4);
                    break;
            case 4: exit(0);
            default:printf("\nInvalid choice..");
        }
    }while(1);
    return 0;
} 
