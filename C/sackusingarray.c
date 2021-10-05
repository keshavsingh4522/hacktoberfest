#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int MAX=10;
struct stack
{
    int top;
    int *array;
    int size;
};
void init(struct stack *st)
{
    st->top=-1;
    st->array= (int *)malloc(MAX*sizeof(int));
    st->size=0;
}
void push(struct stack *st,int item)
{
    if(st->top==MAX-1)
    {
        printf("Stack overflow\n");
        return;
    }
    st->top++;
    st->array[st->top]=item;
    st->size++;
    printf("The item %d is succefully pushed\n",st->array[st->top]);
    getch();
}
int pop(struct stack *st)
{
    if(st->top==-1)
    {
        return NULL;
    }
    int val= st->array[st->top];
    st->top--;
    st->size --;
    return val;
}
int peek(struct stack *st)
{
    if(st->top ==-1)
    {
        return NULL;
    }
    
    return  st->array[st->top];
}
void display(struct stack *st)
{
    if(st->top==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("the elements are :\n");
  
    for(int i=st->top; i>=0;i--)
    {
        printf("%d\n",st->array[i]);
    }
    getch();
}

int main()
{
    struct stack st;
    init(&st);
    int choice, item,pop_value;
    do
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the number to push :");
                    scanf("%d", &item);
                    push(&st,item);
                    break;
            case 2: 
            pop_value =pop(&st);
            if(pop_value==NULL)
                    {
                        printf("Stack Underflow\n");
                        getch();
                    }
                    else
                    {
                        printf("the item which is pooped is %d\n", pop_value);
                        getch();
                    }
                    break;
            case 3: if(peek(&st)==NULL)
                    {
                        printf("Stack is empty\n");
                        getch();
                    }
                    else 
                    {
                        printf("The current item is %d\n", peek(&st));
                        getch();
                    }
                    break;
            case 4:display(&st);
                    break;

            default:break;
        }
    } while (choice !=5);
    
    return 0;
}