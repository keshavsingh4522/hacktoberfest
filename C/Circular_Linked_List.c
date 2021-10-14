#include<stdio.h>
#include<stdlib.h>

/* structure node Created */
struct Node
{
	int data;
	struct Node *next;
};

/* insert the node at the stating of a Circular
linked list */
void push(struct Node **head_ref, int data)
{
	struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
	struct Node *temp = *head_ref;
	ptr1->data = data;
	ptr1->next = *head_ref;

	/* If linked list is not NULL then set the next of last node */
	if (*head_ref != NULL)
	{
		while (temp->next != *head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1; /*For the first node */

	*head_ref = ptr1;
}

/* Function to print nodes in a given Circular linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	if (head != NULL)
	{
		do
		{
			printf("%d ", temp->data);
			temp = temp->next;
		} while (temp != head);
	}
}

/* Driver program to test above functions */
int main()
{
	/* Initialize lists as empty */
	struct Node *head = NULL;

	/* Created linked list will be 11->2->56->12 */
	push(&head, 12);
	push(&head, 56);
	push(&head, 2);
	push(&head, 11);

	printf(" Contents of Circular Linked List \n ");
	printList(head);

	getchar();
	return 0;
}