//Selection Sort
//We seect a position and then find the element that fits that position.
//Starting with position 0, we look for the smallest number in remaining array that would fit the position
//And swap the it with the index position.

//Characterisitcs
//Since in each pass, only one swap is performed, total number of swaps = n-1 = O(n)
//1.Thus, Selection Sort is good for less number of swaps.
//2. Intermediate results of Selection Sort are useful just like Insertion Sort.
//For k-passes, they give the k-smallest elements. Quite useful in algorithms.

//Time Complexity - O(n^2)
//Not Adoptive
//Not Stable

//Implementation
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Selection(int A[], int n)
{
    int j, k;
    for(int i=0; i < n-1; i++)
    {
        for(j=k=i; j < n; j++){
            if(A[j] < A[k])
                k = j;
        }
        swap(&A[i], &A[k]);// 1 swap per pass
    }
}

int main()
{
    int A[] = {45, 36, 14, 78, 24, 52, 83,-11, 232, 6};
    int n = sizeof(A)/sizeof(A[0]);

    Selection(A, n);
    printf("Sorted Array : ");
    for(int i=0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}