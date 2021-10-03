#include<iostream>
using namespace std;
int BinarySearch(int arr[],int n,int x)
{
    int start=0,end=n,mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
            end=mid-1;
        else
            start=mid+1;
    }
    return -1;
}
int main()
{
    int size,search;
    cout<<"Enter size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<size;i++)
        cin>>arr[i];
    cout<<"Enter the element to be searched: ";
    cin>>search;
    int result=BinarySearch(arr,size,search);
    if(result==-1)
        cout<<"Sorry, element not found in the array provided."<<endl;
    else
        cout<<"Element found! On index : "<<result<<endl;
    return 0;
}