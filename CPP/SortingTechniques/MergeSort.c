//MergeSort uses Merge internally to merge two different arrays into a single Array
//Since only one Array is taken into onsideration it tries to sort and merge parts of array, 
//until we array at Sorted Array.
//MergeSort can be applied both iteratively as well as recursively. Both of them use 2-way merging.
//For iterative merge sort, the whole array of size n is taken as combination of n sorted list.
//Then these sorted lists are merged taking 2 at a time(2-way merging) and this process goes on with bigger sorted 
//lists until the whole array gets sorted. 

//Time Complexity - 
//For Iterative Merge sort, for each pass we make n comparsions and there are total O(logn) passes.
//So time complexity = O(nlogn)

//Recursive Merge Sort
//It divides the array into two halves recursively until each divided array contains exactly 1 element.
//Sorts LHS and RHS recursively.
//Avg case time complexity = O(nlogn)
//Merge sort merges the array in Postorder fashion i.e. lchild->rchild->root
//Among comparison based sorting techniques, only merge sort uses auxiliary space.
//It uses space both for auxiliary array - (n) and Stack in recursion - (logn)
//Thus total auxilary space used by merge sort = n + logn

//Merge Sort is stable.

#include <stdio.h>

void Merge(int A[], int l, int mid, int h)
{
    int i=l, j = mid+1, k = 0;
    int C[h-l+1];
    while(i <= mid && j <= h)
    {
        if(A[i] <= A[j])
            C[k++] = A[i++];
        else if(A[i] > A[j])
            C[k++] = A[j++];
    }
    while(i <= mid) C[k++] = A[i++];
    while(j <= h) C[k++] = A[j++];

    for(int i=l; i <= h; i++){A[i] = C[i-l];}
}

void MergeSort(int A[], int l, int h){
    if(l < h)
    {
        int mid = (l+h)/2;
        MergeSort(A, l, mid);
        MergeSort(A, mid+1, h);
        Merge(A, l, mid, h);
    }
}

//Iterative version of Mege Sort
void IMergeSort(int A[], int n)
{
    int p, i, l, mid, h;
    for(p = 2; p <= n; p = p*2){
        for(i = 0; i+p-1 < n; i = i+p){
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(A, l, mid, h);
        }
        if(i < n)
            Merge(A, i, (i+n-1)/2, n-1);
    }
    if(p/2 < n)
        Merge(A, 0, p/2-1, n-1);
}

int main()
{
    int A[] = {8, 3, 7, 4, 9, 2, 6, 14, 89, 31, 12, 67, 76, 105, 0};
    int n = sizeof(A)/sizeof(A[0]);

    IMergeSort(A, n);
    //Display
    printf("Sorted : ");
    for(int i=0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}