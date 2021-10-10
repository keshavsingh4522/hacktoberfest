//Count Sort
//Count Sort counts the number of occurrences of each array element in seperate count array.
//Then it refills the main array according to the occurrences of deiffenet elements.
//It is easiest, fastest, but consumes a lot of memory since it is dependent on maximum element.
//Time Complexity : O(n)
//Space Complexity : O(n) where n is the max element in the array.

//Count Sort is best when it comes to small ranges, but is not effcient for huge ranges.

//Implementation
#include <stdio.h>
#include <stdlib.h>

int Max(int A[], int n)
{
    int max = -32768;
    for(int i=0; i < n; i++)
        if(A[i] > max) max = A[i];
    return max;
}

void CountSort(int A[], int n)
{
    int max = Max(A, n);
    int *C = (int*)malloc((max+1)*sizeof(int));

    for(int i=0; i < max+1; i++) C[i] = 0;//Initilization
    for(int i=0; i < n; i++) C[A[i]]++; //Count

    int i=0, j=0;
    while(i < max+1)
    {
        if(C[i] > 0){
            A[j++] = i;
            C[i]--;
        }
        else i++;
    }

}


int main()
{
    int A[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
    int n = sizeof(A)/sizeof(A[0]);

    CountSort(A, n);
    //Display
    printf("Sorted : ");
    for(int i=0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
