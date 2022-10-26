#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
} *first = NULL;

void create(int A[], int n)
{
    Node *t, *last;
    int i;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (int i = 1; i < n; ++i)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev == last;
        last->next = t;
        last = t;
    }
}

void Display(Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int Length(Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void insert(Node *p, int index, int x)
{
    Node *t;
    int i;
    if (index < 0 || index > Length(p))
        return;

    if (index == 0)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t = new Node;
        t->data = x;

        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int Delete(Node *p, int index)
{
    int x = -1;
    Node *q;
    if (index < 1 || index > Length(p))
        return -1;

    if (index == 1)
    {
        first = first->next;
        if (first)
            first->prev = NULL;
        x = p->data;
        delete p;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;

        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

void Reverse(Node *p)
{
    Node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        p = p->prev;
        if (p->next == NULL && p != NULL)
            first = p;
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    cout << "Display LL: ";
    Display(first);
    cout << "\nLength is: " << Length(first);
    insert(first, 0, 5);
    cout << "\nDisplay after insertion: ";
    Display(first);
    insert(first, 5, 45);
    cout << "\nDisplay after insertion: ";
    Display(first);
    cout << "\nDeleted Element: " << Delete(first, 1);
    cout << "\nDisplay after Deletion: ";
    Display(first);
    cout << "\nDeleted Element: " << Delete(first, 5);
    cout << "\nDisplay after Deletion: ";
    Display(first);
    Reverse(first);
    cout << "\nDisplay after Reversing: ";
    Display(first);

    return 0;
}



