#include <iostream>
using namespace std;

int linearSearch(int arr[], int value)
{
    for(int i=0;i<5;i++)
    {
        if(arr[i]==value)
        return i; 
    }
    return 0;
}


int main() {
    // find position/index of 4
    //T(n)=O(n)
    int arr[]={10,2,3,4,5};
    int i;
    int value=4;
    cout<<"given array is:\n";
    for(i=0;i<5;i++)
    cout<<arr[i]<<" \n";
    
    cout<<"index of 4 is = "<<linearSearch(arr,value);
    return 0;
}
