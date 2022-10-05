#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*top=NULL;

void push()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data : ");
	scanf("%d",&newnode->data);
	if(top==NULL)
		newnode->next=NULL;
	else
		newnode->next=top;
	top=newnode;
}

int pop()
{
	if(top==NULL)
	{
		printf("\nUnderflow!!");
		return -1;
	}
	else
	{	
		int x=top->data;
		struct node *temp;
		temp=top;
		top=top->next;
		free(temp);
		return x;
	}
}

void display()
{
	struct node	*temp;
	temp=top;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main()
{
	int ch;
	do
	{
		printf("\n1 : Push");
		printf("\n2 : Pop");
		printf("\n3 : Display");
		printf("\n4 : Quit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
                display();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default :
				printf("\nWrong choice.");
		}
	}
    while(ch!=4);
	return 0;
}
	
