// code is contributed by harsh

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*top=NULL;


void push(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));

    if(t==NULL)
        printf("stack is full\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }

}


int pop()
{
    struct Node *t;
    int x=-1;

    if(top==NULL)
        printf("Stack is Empty\n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }

    return x;
}


void Display()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}


int main()
{
    int n;
    printf("give the number of element in stack :");
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        int a;
        printf("give the %d element of stack :",i+1);
        scanf("%d",&a);
        scanf("%d",push(a));
    }
    

    printf("%d ",pop());

    return 0;
}