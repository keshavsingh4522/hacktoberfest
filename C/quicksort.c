#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arr[] = {2, 9, 3, 7, 4};
    int n = 5;
    // insertionsort(arr,n);
    print(arr,n);
    quicksort(arr, 0, n-1);
    print(arr,n);
    return 0;
}
int partition(int *arr, int low, int high){
int i,j,temp;
do{
    int pivot = arr[low];
    i = low + 1;
     j = high;
    while (arr[i] <= pivot)
    {
        i++;
    }
    while (arr[i] > pivot)
    {
        j--;
    }
    if (i < j)
    {
        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
    }
}while(i<j);
}
int print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int quicksort(int *arr, int low, int high)
{
    int pi; //index of pivot after partition
    if (low < high)
    {
        pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1); //sort left subarray
        quicksort(arr, pi + 1, high); //sort right subarray
    }
}
