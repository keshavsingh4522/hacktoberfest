// circular linked list using double pointer
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *next;
};
void create_cirlinked_list(struct node **last, int number)
{
    struct node *ptr, *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &ptr->item);
    *last = ptr;
    (*last)->next = ptr;
    for (int i = 1; i < number; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &p->item);
        p->next = (*last)->next;
        (*last)->next = p;
        *last = p;
    }
    //  printf("%d",(*last)->item);
    // printf("%d",(*last)->next->item);
    //  getch();
}
void create_second_cirlinked_list(struct node **last1, int number)
{
    struct node *ptr, *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &ptr->item);
    *last1 = ptr;
    (*last1)->next = ptr;
    for (int i = 1; i < number; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &p->item);
        p->next = (*last1)->next;
        (*last1)->next = p;
        *last1 = p;
    }
    //  printf("%d",(*last)->item);
    // printf("%d",(*last)->next->item);
    //  getch();
}
void view(struct node **last)
{
    struct node *ptr;
    if (*last == NULL)
    {
        printf("circular linked list is empty:\n");
    }
    else
    {
        printf("node of circular linked list is ......>\n\n");
        ptr = (*last)->next;
        while (ptr->next != (*last)->next)
        {
            printf(" %d  ", ptr->item);
            ptr = ptr->next;
        }
        printf(" %d ", ptr->item);
    }
}
void insert_At_first(struct node **last, int data)
{
    struct node *p;
    if (*last == NULL)
    {
        p = malloc(sizeof(struct node));
        p->item = data;
        *last = p;
        (*last)->next = p;
        //   printf("your data is %d",(*last)->next->item);
        //   getch();
    }
    else
    {
        p = malloc(sizeof(struct node));
        p->item = data;
        p->next = (*last)->next;
        (*last)->next = p;

        // printf("%d",(*last)->next->item);
        // getch();
    }
}
void inser_At_last(struct node **last, int data)
{
    struct node *ptr;
    if (*last == NULL)
    {
        ptr = malloc(sizeof(struct node));
        ptr->item = data;
        *last = ptr;
        (*last)->next = ptr;

        // printf("data is %d", (*last)->next->item);
    }
    else
    {
        ptr = malloc(sizeof(struct node));
        ptr->item = data;
        ptr->next = (*last)->next;
        (*last)->next = ptr;
        *last = ptr;
    }
}
void insert_At_After(struct node **last, struct node *t, int data)
{
    struct node *ptr;
    ptr = malloc(sizeof(struct node));
    ptr->item = data;
    ptr->next = t->next;
    t->next = ptr;
    if (t == *last)
    {
        *last = ptr;
    }
}
void insert_At_index(struct node **last, int index, int data)
{
    struct node *ptr, *n;
    ptr = malloc(sizeof(struct node));
    ptr->item = data;
    if (*last == NULL)
    {
        ptr->next = ptr;
        *last = ptr;
    }
    else if (*last == (*last)->next)
    {
        ptr->next = (*last)->next;
        (*last)->next = ptr;
    }
    else if (index <= 0)
    {
        ptr->next = (*last)->next;
        (*last)->next = ptr;
    }
    else
    {
        n = (*last)->next;
        for (int i = 0; i < index - 1; i++)
        {
            n = n->next;
        }
        ptr->next = n->next;
        n->next = ptr;
    }
}
void delete_At_first(struct node **last)
{
    struct node *ptr;
    if (*last == NULL)
    {
        printf("circular linked list is empty:");
        getch();
    }
    else
    {
        ptr = (*last)->next;
        (*last)->next = ptr->next;
        if (*last == (*last)->next)
        {
            // free(*last);
            *last = NULL;
        }
        free(ptr);
    }
}
void delete_At_last(struct node **last)
{
    struct node *ptr;
    if (*last == NULL)
    {
        printf("circular linked list is empty:");
        getch();
    }
    else
    {
        if (*last == (*last)->next)
        {
            *last = NULL;
            free(*last);
        }
        else
        {
            ptr = (*last)->next;
            while (ptr->next != *last)
            {
                ptr = ptr->next;
            }
            ptr->next = (*last)->next;
            free(*last);
            *last = ptr;
        }
    }
}
void delete_At_index(struct node **last, int index)
{
    struct node *ptr, *n;
    n = NULL;
    if (*last == NULL)
    {
        printf("circular linked list is empty:");
        getch();
    }
    else if (*last == (*last)->next)
    {
        free(*last);
        *last = NULL;
    }
    else if (index <= 0)
    {
        ptr = (*last)->next;
        (*last)->next = ptr->next;
        free(ptr);
    }
    else
    {
        ptr = (*last)->next;
        for (int i = 0; i < index; i++)
        {
            n = ptr;
            ptr = ptr->next;
        }
        n->next = ptr->next;
        free(ptr);
    }
}
void delete_At_node(struct node **last, struct node *t)
{
    struct node *ptr;
    if (*last != NULL)
    {
        if (*last == t && *last == (*last)->next)
        {
            *last = NULL;
            free(*last);
        }
        else
        {
            ptr = (*last)->next;
            while (ptr->next != t)
            {
                ptr = ptr->next;
            }
            ptr->next = t->next;
            if (t == *last)
            {
                free(*last);

                // ptr->next = t->next;
                *last = ptr;
            }
            free(t);
        }
    }
}
int main()
{
    int choice, index, count, data, number;
    struct node *last = NULL;
    struct node *last1 = NULL;
    struct node *temp;
    while (1)
    {
        system("cls");
        view(&last);
        printf("\n 1. create_circular_linkedlist:");
        printf("\n 2. insert_At_first");
        printf("\n 3. insert_At_last:");
        printf("\n 4. insert_At_after:");
        printf("\n 5. insert_at_index:");
        printf("\n 6. delete_At_first:");
        printf("\n 7. delete_At_last:");
        printf("\n 8. delete_At_index:");
        printf("\n 9. delete_At_node:");
        printf("\n 10. exit:\n");
        printf("enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf(" how many node do you want in circualr linked list:");
            scanf("%d", &number);
            create_cirlinked_list(&last, number);
            break;
        case 2:
            printf("enter your data :");
            scanf("%d", &data);
            insert_At_first(&last, data);
            break;
        case 3:
            printf("enter your data:");
            scanf("%d", &data);
            inser_At_last(&last, data);
            break;
        case 4:
            printf("after which data do you want to add new node :");
            scanf("%d", &data);
            temp = search(&last, data);
            printf("enter which data do you want to insert:");
            scanf("%d", &data);
            insert_At_After(&last, temp, data);
            break;
        case 5:
            printf("enter your index (strat from 0) to given index:");
            scanf("%d", &index);
            printf("enter your data do you want to insert:");
            scanf("%d", &data);
            insert_At_index(&last, index, data);
            break;
        case 6:
            delete_At_first(&last);
            break;
        case 7:
            delete_At_last(&last);
            break;
        case 8:
            printf("enter your index do you want to delete that index:");
            scanf("%d", &index);
            delete_At_index(&last, index);
            break;
        case 9:
            printf("which data of node do you want to delete :");
            scanf("%d", &data);
            temp = search(&last, data);
            delete_At_node(&last, temp);
            break;
        
        case 10:
            printf("THANK YOU \n PRESS ANY KEY to exit....>");
            getch();
            exit(0);
        default:
            printf("invalid choice");
        }
    }
    return 0;
}
