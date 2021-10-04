/* Circular linked lists program */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Structure of node */
struct node
{
    int data;
    struct node *next;
};

/* Pointer variables */
struct node *new_node;
struct node *start;
struct node *current;
struct node *delvab;
struct node *preptr;

/* Creating a Circular linked list */
void create()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Memory is not available");
    }
    else
    {
        printf("Enter data to your node: ");
        scanf("%d", &new_node->data);
        new_node->next = start;
    }
    if (start == NULL)
    {
        start = new_node;
        current = start;
        current->next = start;
    }
    else
    {
        current->next = new_node;
        current = new_node;
        current->next = start;
    }
}

/* Inserting node at beginning */
void insertbeg()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = NULL;
    if (new_node == NULL)
    {
        printf("Memory is not available.. \n");
    }
    else
    {
        if (start == NULL)
        {
            printf("No elements is in list \n");
        }
        else
        {
            printf("Enter data to your first node: ");
            scanf("%d", &new_node->data);
            while (current->next != start)
            {
                current = current->next;
            }
            current->next = new_node;
            new_node->next = start;
            start = new_node;
        }
    }
}

/* Inserting node at end */
void insertend()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = NULL;
    if (new_node == NULL)
    {
        printf("Memory is not available.. \n");
    }
    else
    {
        printf("Enter data to your last node: ");
        scanf("%d", &new_node->data);
        current = start;
        while (current->next != start)
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->next = start;
    }
}

/* Display nodes information */
void display()
{
    if (start == NULL)
    {
        printf("No node is present in list or list is empty \n ");
    }
    else
    {
        current = start;
        while (current->next != start)
        {
            printf("Node address: %p Node data: %d Node next address: %p \n", current, current->data, current->next);
            current = current->next;
        }
        printf("Node address: %p Node data: %d Node next address: %p \n", current, current->data, current->next);
    }
}

/* Inserting node in between */
void insertbtw()
{
    int num;
    current = start;
    preptr = current;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Memory is not available \n");
    }

    else
    {
        display();
        printf("Enter data after which to insert new_node ");
        scanf("%d", &num);

        current = start;
        preptr = current;
        if (num == current->data)
        {
            current = current->next;
            preptr->next = new_node;
            new_node->next = current;
            printf("Enter data to your node ");
            scanf("%d", &new_node->data);
        }
        else
        {
            while (preptr->data != num)
            {
                preptr = current;
                current = current->next;
            }
            preptr->next = new_node;
            new_node->next = current;
            printf("Enter data to your node ");
            scanf("%d", &new_node->data);
        }
    }
}

/* Delete node at beginning */
void delbeg()
{
    if (start == NULL)
    {
        printf("Can't delete node.. list is empty \n");
    }
    else
    {
        current = start;
        while (current->next != start)
        {
            current = current->next;
        }
        delvab = start;
        current->next = start->next;
        start = start->next;
        free(delvab);
        printf("Node is deleted Successfully.. \n");
    }
}

/* Delete node at end */
void delend()
{
    if (start == NULL)
    {
        printf("Can't delete node.. list is empty \n");
    }
    else
    {
        current = start;
        while (current->next != start)
        {
            preptr = current;
            current = current->next;
        }
        delvab = current;
        preptr->next = start;
        free(delvab);
        printf("Node is deleted Successfully.. \n");
    }
}

/* Deleting node in between */
void delbtw()
{
    int num;
    display();
    if (start == NULL)
    {
        printf("You can't delete as list is empty");
    }
    else
    {
        printf("Enter data after which to delete node : ");
        scanf("%d", &num);
        current = start;
        preptr = current;
        if (num == preptr->data)
        {
            preptr = current;
            current = current->next;
            delvab = current;
            preptr->next = current->next;
            free(delvab);
        }
        else
        {
            while (preptr->data != num)
            {
                preptr = current;
                current = current->next;
            }
            delvab = current;
            preptr->next = current->next;
            free(delvab);
            printf("Node is deleted Successfully.. \n");
        }
    }
}

/* main function */
void main()
{
    int choice, ans = 1;

    while (ans == 1)
    {
        printf("1. Create \n");
        printf("2. Display \n");
        printf("3. Exit \n");
        printf("4. Insert_at_beg \n");
        printf("5. Insert_at_end \n");
        printf("6. Delete_at_beg \n");
        printf("7. Delete_at_end \n");
        printf("8. Insert_in_between \n");
        printf("9. Delete_in_between \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(1);
            break;
        case 4:
            insertbeg();
            break;
        case 5:
            insertend();
            break;
        case 6:
            delbeg();
            break;
        case 7:
            delend();
            break;
        case 8:
            insertbtw();
            break;
        case 9:
            delbtw();
            break;
        default:
            printf("Enter correct choice.. \n");
            break;
        }
        printf("Do you want to continue ? (1 or 0) ");
        scanf("%d", &ans);
    }
    getch();
}
