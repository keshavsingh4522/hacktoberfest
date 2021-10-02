#include <iostream>
using namespace std;

int kadane(int arr[], int n){
    int res = 0;
    int maxEnding = 0;
    for(int i=0; i<n; i++){
        maxEnding += arr[i];
        res = max(res,maxEnding);
        if(maxEnding < 0){
            maxEnding = 0;
        }
    }

    return res;
}

int main(){
    int arr[] = {1,2,3,4,5};
    cout<< kadane(arr, 5);
    return 0;
}