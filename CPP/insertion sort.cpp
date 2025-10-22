//Insertion sort

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s,i,j,current;
    cout<<"enter size of array :";
    cin>>s;
    int arr[s];
    for(i=0;i<s;i++)
    {
        cin>>arr[i];
    }
    
    for(i=1;i<s;i++)
    {
        current=arr[i];
        j=i-1;
        
        while(arr[j]>current&&j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        j++;
        arr[j]=current;
    }
    for(i=0;i<s;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
