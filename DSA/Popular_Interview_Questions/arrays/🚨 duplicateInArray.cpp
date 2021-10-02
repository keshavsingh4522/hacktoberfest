#include <iostream>
using namespace std;

//returns only one duplicated element in an array

int duplicate(int arr[], int n){
    int i=0;
    while(arr[i]>0){
        arr[i] *= -1;
        i = abs(arr[i]);
    }
    return i;
}

int main(){
    int arr[] = {1,2,2,3,4};
    int n=5;
    return 0;
}