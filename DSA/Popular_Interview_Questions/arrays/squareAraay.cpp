#include <iostream>
using namespace std;

vector<int> squaredArray(vector<int> arr){
    int n = arr.size();
    vector<int> res(n);
    int start = 0; 
    int end = n-1;
    int index = n-1;

    while(start <= end){
        if(abs(arr[start]) < abs(arr[end]){
            res[index--] = arr[end] * arr[end];
            end--;
        })
        else{
            res[index--] = arr[start] * arr[start];
            start++;
        }
    }

    return res;
}

int main(){


    return 0;
}