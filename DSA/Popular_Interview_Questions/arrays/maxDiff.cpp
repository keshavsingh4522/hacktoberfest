#include <iostream>
using namespace std;

int maxDiff(int arr[], int n){
    int res = arr[1] - arr[0];
    int minVal = arr[0];
    for(int i=1; i<n; i++){
        res = max(res, arr[i] - minVal);;
        minVal = min(min, arr[i]);
    }

    return res;
}

int main(){
    
    return 0;
}