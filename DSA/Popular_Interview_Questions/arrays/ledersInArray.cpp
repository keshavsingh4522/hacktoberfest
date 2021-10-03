#include <iostream>
using namespace std;

void printLeaders(int arr[], int n){
    int curr = arr[n-1];
    cout<<curr;
    for(int i = n-2; i>=0; i--){
        if(arr[i]>curr){
            cout<<arr[i];
            curr = arr[i];
        }
    }
}

int main(){

    return 0;
}