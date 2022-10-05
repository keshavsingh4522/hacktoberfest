#include <iostream>
using namespace std;

void stock_price(int arr[], int n){
    int initial = arr[0];
    int final;
    int profit=0;
    for(int i=0;i<n;i++){
        if(arr[i+1]<arr[i]){
            profit+=arr[i]-initial;
            initial=arr[i+1];
        }
    }
    cout<<profit;
}


int main(){
    int arr[5]={9,8,10,7,7};
    stock_price(arr,5);



}