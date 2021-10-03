#include <iostream>
using namespace std;

void rotate(int a[], int n)
{   
    int temp=a[n-1];
    for(int i=n-1;i>0;i--)
    {
        a[i]=a[i-1];
    }
    a[0]=temp;
    
}

int main(){

    int arr[] = {1,2,3,4,5};
    rotate(arr, 5);

    for(int i=0; i<5; i++){
        cout<<arr[i];
    }

    return 0;
}