//  A code to perform binary search on an array
#include <iostream>
#include <cmath>
using namespace std;
// Function to return index of searched element
int binaryReturn(int arr[], int size, int key){
    int l=0, h= (size-1), mid;
    while(l<=h){
        
        mid = l + (h - l) / 2;
        
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            l = mid+1;
        else
            h = mid-1; 
    }
    return -1;
}
//Driver code
int main(){
    int arr[12]={1,2,3,4,5,6,7,8,9,10,44,46};
    int size= sizeof(arr)/sizeof(int);
    int key= 46;
    cout<<binaryReturn(arr, size, key);
    return 0;
}
