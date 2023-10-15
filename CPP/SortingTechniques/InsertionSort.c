//This is a program to display Insertion Sort
//In Insertion sort we insert the new element in a Sorted Array or LL
//In Array, we will have to shift the elment every time the element in consid is greater than the new element.
//This takes time.
//However, For Linked List we simply have to search for its position and simply insert at that position.
//And this is why, Insertion Sort is more compatible with linked list as compared to array.

//The time complexity for Insertion an element in both Array and linked list is O(n)-max and O(1)-min.
//Insertion Sort is adoptive by nature as it takes O(n) time for sorted array.
//Further it is also stable at same time.
//Time Complexity for n elements : Max - O(n^2){reverse sorted} Min-O(n){sorted}
//No of Swaps : Max - O(n^2){reverse sorted} Min-O(1){sorted}

#include <stdio.h>
#include <stdlib.h>

//Array
void Insertion(int A[], int n)
{
    int j, x;
    for(int i=1; i < n; i++){
        j = i-1;
        x = A[i];
        while(j > -1 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}


//Linked List
struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void InsertionLL(int A[], int n)
{
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = A[0];
    t->next = NULL; 
    first = t;

    struct Node *p, *q;
    for(int i=1; i < n; i++)
    {
        p = first, q= NULL;
        while(p && A[i] > p->data){
            q = p;
            p = p->next;
        }
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        if(p == first){t->next = first; first = t; continue;}
        t->next = q->next;
        q->next = t;
    }
}

//Display Linked List
void Display(struct Node *p){
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int A[] = {62, 23, 51, 79, 6, 19, 97, 39, 120};
    int n = sizeof(A)/sizeof(A[0]);

    //LL Insertion Sort
    InsertionLL(A, n);
    printf("Sorted LL : ");
    Display(first);

    //Array Sorted
    Insertion(A, n);
    printf("Sorted : ");
    for(int i=0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}