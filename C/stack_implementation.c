#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 5
int stack[SIZE];
int top = -1;


void push(int val) {
	if (top == SIZE - 1)
		printf("Stack is Full\n");
	else {
		top = top + 1;
		stack[top] = val;
		printf("Pushed value: %d\n", val);
	}
}

void pop() {
	if (top == -1)
		printf("Stack is Empty\n");
	else {
		printf("Poped value: %d\n", stack[top]);
		top = top - 1;
	}
}

void display() {
	if (top == -1)
		printf("Stack is Empty");
	else {
		printf("Stack: ");
		for (int i = 0; i <= top ; ++i)
			printf("%d ", stack[i]);
	}
	printf("\n");

}

int main()
{
	int ch, ele;

	while (1) {
		system("cls");
		printf("1) Push\n");
		printf("2) Pop\n");
		printf("3) Display\n");
		printf("4) Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);

		printf("\n");
		switch (ch)
		{
		case 1:
			if (top == SIZE - 1)
				printf("Stack is Full\n");
			else {
				printf("Enter value to push: ");
				scanf("%d", &ele);
				push(ele);
			}
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			printf("\n*** Thanks for using Stack ***\n\n");
			exit(0);
		default:
			printf("Invalid Choice, Please Enter Valid choice.\n");
		}
		getch();
	}
	return 0;
}
