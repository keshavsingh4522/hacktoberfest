#include <iostream>
using namespace std;

int binarySearch(int arr[], int value)
{
    int start=0;
    int end=5;
    int mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==value)
        return mid;
        if(arr[mid]<value)
        start=mid+1;
        if(arr[mid]>value)
        end=mid-1;
    }
    return 0;
}


int main() {
    // find position/index of 4 provided the array should be sorted
    //instead of comparing to first element of array we will compare it to middle element
    //T(n)=O(logn)
    int arr[]={1,2,3,4,5};
    int i;
    int value=4;
    cout<<"given array is:\n";
    for(i=0;i<5;i++)
    cout<<arr[i]<<" \n";
    
    cout<<"index of 4 is = "<<binarySearch(arr,value);
    return 0;
}
