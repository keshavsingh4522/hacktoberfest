//Shell Sort
//Shell Sort is usefu for sorting very lagre size array.
//Shell Sort is based on Insertion Sort. We follow the same procedure as in insertion sort.
//Only that this time, a gap is introduced between each element which rduces by half after each pass.
//Initially gap between two elements to consider for insertion sort is floor(n/2).

//Time Complexity
//Shell sort comes with many variation depending what we choose for gap.
//If we take n/2 as gap, then time complexity = O(nlogn)
//Some other variations include O(n^3/2) and O(n^5/3) for prime numbers as gap.
//Shell sort does inplace sorting so no extra space is required.

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ShellSort(int A[], int n)
{
    int j, x;
    int gap = n/2;
    while(gap > 0){
        for(int i = 0; i < n; i++)
        {
            if(i+gap < n && A[i+gap] < A[i]) swap(&A[i], &A[i+gap]);
            j = i-gap;
            x = A[i];
            while(j > -1 && A[j] > x){
                A[j+gap] = A[j];
                j = j-gap;
            }
            A[j+gap] = x;
        }
        gap = gap/2;
    }
}

int main()
{
    int A[] = {62, 23, 51, 79, 6, 19, 28, 39, 120};
    int n = sizeof(A)/sizeof(A[0]);

    //Array Sorted
    ShellSort(A, n);
    printf("Sorted : ");
    for(int i=0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}