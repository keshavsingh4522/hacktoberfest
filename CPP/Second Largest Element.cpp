//Second largest element

#include<iostream>
using namespace std;

void bsort(int arr[],int n)
{
    int t;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    
    cout<<"Second largest element :"<<arr[n-2];
}

int main()
{
    cout<<"Enter size of array :";
    int n;
    cin>>n;
    int arr[n];
    
    cout<<"Enter array elements :";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    bsort(arr,n);
    
}
