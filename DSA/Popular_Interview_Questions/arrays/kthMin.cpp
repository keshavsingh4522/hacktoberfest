#include <iostream>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
        sort(arr, arr+r+1);
        return arr[k-1];
    }

int main(){
    int arr[] = {1,2,7,4,5};
    cout<<kthSmallest(arr, 0, 5, 3);
    return 0;
}