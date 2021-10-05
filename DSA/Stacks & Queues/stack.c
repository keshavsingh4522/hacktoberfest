#include<stdio.h>
#include<conio.h>
#define MAX 10
int st[MAX],top=-1;
void push(int val);
int pop();
int peek();
void display ();
int main()
{
  int val, option,f=1;
  while(f!=0)
  {
    printf("\n****MAIN MENU****");
    printf("\n1.PUSH");
    printf("\n2.POP");
    printf("\n3.PEEK");
    printf("\n4.DISPLAY");
    printf("\n5.EXIT");
    printf("\n*********************");
    printf("\n\nEnter your option");
    scanf("%d",&option);
    switch(option)
    {
      case 1:
            printf("\n Enter the number to be pushed on the stack");
            scanf("%d",&val);
            push(val);
            break;
      case 2:
            val = pop(st);
            printf("\nThe value deleted from the stack is %d",val);
            break;
      case 3:
            val = peek();
            printf("\n The value stored at the top of the stack is %d",val);
            break;
      case 4:
            display();
            break;
      case 5: f=0;
      		  break;
      default:  printf("\n Enter correct choice..");
    }
  }

}

void push (int val)
{
  if(top==MAX-1)
  {
    printf("\nSTACK OVERFLOW");
  }
  else
  {
    top++;
    st[top]=val;
  }
}

int pop()
{
  int val;
  if (top ==-1)
  {
    printf("\nSTACK UNDERFLOW");
    return -1;
  }
  else
  {
    val=st[top];
    top--;
    return val;
  }
}

void display()
{
  int i;
   if (top == -1)
    printf("\nSTACK IS EMPTY");
    else
    {
      for(i=top;i>=0;i--)
      printf("\n%d",st[i]);
    }
}

int peek()
{
  if(top==-1)
  {
    printf("\n STACK IS EMPTY");
  }
  else
  printf("%d",st[top]);
}
