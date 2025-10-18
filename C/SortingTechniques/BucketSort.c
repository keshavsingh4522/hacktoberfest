//Bin/Bucket Sort
//Bin/Bucket Sort is similar to Count Sort except that instead of storing the count of occurrences, it stores
//each of the occurrence as a seperate node within the Array in form of a linked list at specified position.
//Time Complexity : O(n)
//Space Compplexity : O(m+n) = O(n)
//where m = max element in Array  & n = size of the array

#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -32768

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* Insert(Node *p, int x)
{
    Node *first = p;
    Node *t = (Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(p == NULL){
        p = t;
        first = t;
    }else{
        while(p->next) p = p->next;
        p->next = t;
        p = p->next;
    }
    return first;
}

Node* Delete(Node *first){
    if(first == NULL) return NULL;
    Node *p = first;
    first = first->next;
    int x = p->data;
    free(p);
    return first;
}

int Front(Node *first)
{
    if(first) return first->data;
    return -1;
}

int Max(int A[], int n)
{
    int max = INT_MIN;
    for(int i=0; i <n; i++)
    {
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

void BucketSort(int A[], int n)
{
    int max = Max(A, n);
    Node **C = (Node**)malloc((max+1)*sizeof(Node*));

    for(int i=0; i < max+1; i++) C[i] = NULL;//intialization
    for(int i=0; i < n; i++) C[A[i]] = Insert(C[A[i]], A[i]); // Insertion

    int i=0, j=0;
    while(j < max + 1)
    {
        if(C[j])
        {
            A[i++] = Front(C[j]);
            C[j] = Delete(C[j]);
        }
        else
            j++;
    }
}


int main()
{
    int A[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
    int n = sizeof(A)/sizeof(A[0]);

    BucketSort(A, n);
    //Display
    printf("Sorted : ");
    for(int i=0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}