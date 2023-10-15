//Implementation of QuickSort
//QuickSort
//QuickSort is not the fastest sorting algorithm out there...
//QuickSort works on thte idea that ana element is in a sorted position, if all elements before that element are
//smaller and all elements after it are greater than that element.
//QuickSort takes O(nlogn) time in general case, and O(n^2) time in case of sorted or reverse sorted array.
//In normal case, the answer is only dependent on patitioning while in sorted case it depends both on sorted and partioning
//The average time complexity of QuickSort is O(nlogn)

//QuickSort employs partioning procedure for sorting the element, and is recursive in nature.
//Since it employs Partioning Procedure. it is also called Partioning exchange Sort.
//It shares a similarity to Selection Sort in way it also selects an element and finds its position, contrary to
//Selection sort which selects a position and finds out the element for that position.
//Hence, its also called Selection Exchange Sort.

//QuickSort in neither adoptive nor stable.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp =*a;
    *a = *b;
    *b = temp;
}

int Partition(int A[], int  l, int h)
{
    //Slight Modification by swapping with Middle element
    //ensures O(nlogn) time in case of Sorted Array
    int mid = (l+h)/2;
    swap(&A[l], &A[mid]);

    int pivot = A[l];
    int i=l;
    int j=h;
    do
    {
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);
        if(i < j)
            swap(&A[i], &A[j]);
    }while(i < j);
    swap(&A[l], &A[j]);
    return j;
}

//A modified version of QuickSort, in whcich we take a random element as pivot by swappping it with first element
int Randomized_Partition(int A[], int l, int h)
{  
    //Choosing a random number as pivot
    srand(time(0));
    int pivot_index = l + rand()%(h-l);
    swap(&A[l], &A[pivot_index]);
    
    int i = l, j = h;
    int pivot = A[l];
    do
    {
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);
        if(i < j)
            swap(&A[i], &A[j]);
    }while(i < j);
    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h)
{
    if(l < h)
    {
        int pivot = Randomized_Partition(A, l, h);
        QuickSort(A, l, pivot);
        QuickSort(A, pivot+1, h);
    }
}

int main()
{
    int A[] = {2, 43, 12, 34, 87, 6, 14, 39, 55, 0, -36, __INT32_MAX__};
    int n = sizeof(A)/sizeof(A[0]);

    QuickSort(A, 0, n-1);
    printf("Sorted : ");
    for(int i=0; i < n-1; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}