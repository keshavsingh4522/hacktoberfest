#include <stdio.h>

//Bubble Sort takes n-1 passes, n(n-1)/2 comparisons and n(n-1)/2 swaps(max no of swaps) in general
//Normally, time complexity of Bubble Sort is O(n^2)
//However, it can be made adoptive by introducting a flag(0) which changes to 1 for any swap
//If no swap found in particular pass we simply break
//In this for already sorted element time complexity reduces to a mere O(n)

//Analysis
//Time Complexity : Min - O(n), Max - O(n^2)
//Bubble Sort is adoptive, stable, and doesn't require extra space

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int A[], int n)
{
    int flag;
    for(int i=0; i < n-1; i++){
        flag = 0;
        for(int j=0; j< n-i-1; j++){
            if(A[j] > A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}


int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int n = sizeof(A)/sizeof(A[0]);
    
    BubbleSort(A, n);
    //Display
    printf("Sorted : ");
    for(int i =0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}