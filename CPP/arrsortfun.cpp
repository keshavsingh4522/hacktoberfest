#include <iostream>
using namespace std;

bool sorted(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]) return false;
    }

    return true;
}

int main(){
    int arr[]={1,5,3,4};
    int n=4;
   cout<<sorted(arr,n);
}