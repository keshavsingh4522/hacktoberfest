// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    int arr[]={10,2,3,4,5};
    int i;
    int min_value=arr[0];
    int max_value=arr[0];
    cout<<"given array is:\n";
    for(i=0;i<5;i++)
    cout<<arr[i]<<" \n";
    for(i=0;i<5;i++)
    {
        if(min_value>arr[i])
        min_value=arr[i];
        if(max_value<arr[i])
        max_value=arr[i];
    }
    
    cout<<"maximum number is="<<max_value;
    cout<<"\nminimum number is="<<min_value;
    return 0;
}
