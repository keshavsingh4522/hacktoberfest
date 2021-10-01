#include<bits/stdc++.h>
using namespace std;
void reverse(int arr[],int low,int high)
{
    while(low<high)
    {
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
    

}
void left_rotate(int arr[],int d,int n)
{
    reverse(arr,0,d);
    reverse(arr,d+1,n-1);
    reverse(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }

}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,0};
    int n=10;
    int d=3;
    left_rotate(arr,d,n); 
}        

  