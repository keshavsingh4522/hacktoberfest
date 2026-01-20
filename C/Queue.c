#include<stdio.h>
int size, head=-1, tail=-1;
int arr[10];

void enqueue(int arr[size],int*head,int size,int*tail)
{ int element;
    if(*tail>size-2)
    {
        printf("Enqueue not a valid expression. Overflow error.\n");
    }
    else
    {   if(*head==-1)
        {
        *head=0;
        }
        *tail=*tail+1;
        printf("Enter the element to be enqueued: ");
        scanf("%d", &element);
        arr[*tail]=element;
        printf("The element %d has been queued successfully. \n",element);
    }
}


void dequeue(int arr[size],int*head,int size,int*tail)
{ int rem;
    if(*head>*tail)
    {
        printf("Dequeue is not a valid expression. Underflow error.\n");
    }
    else
    {
        rem=arr[*head];
        *head=*head+1;
        printf("The element %d has been dequeued sucessfully.\n",rem);
    }
}


void display(int arr[size],int*head,int size,int*tail)
{
    int i;
   

    if(*head==-1 & *tail==-1)
    {
        printf("The queue is empty. \n");
    }
    else
    {
        printf("The queue is currently: \n");
        for(i=*head;i<=*tail;i++)
        {
            printf("%d ",arr[i]);
        }
    }
    printf("\n");

}

int main()
{   int size,op,end=0;
    printf("Enter the size of the array:\n");
    scanf("%d",&size);
    while(end!=2)
    {
    printf("Enter the operation to be performed:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    scanf("%d",&op);

    switch (op)
    {
    case 1:
        enqueue(arr,&head,size,&tail);
        break;

    case 2:
        dequeue(arr,&head,size,&tail);
        break;

    case 3:
        display(arr,&head,size,&tail);
        break;

    default:
        printf("Invalid Operation.\n");
        end=2;
        break;
    }

    }
}





