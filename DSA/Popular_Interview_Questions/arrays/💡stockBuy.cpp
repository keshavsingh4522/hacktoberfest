#include <iostream>
using namespace std;

int profit(int arr[], int n){
    int profit = 0;
    for(int i=1; i<n; i++){
        if(arr[i] > arr[i-1]){
            profit += (arr[i] - arr[i-1]);
        }
    }

    return profit;
}


int main(){

    return 0;
}