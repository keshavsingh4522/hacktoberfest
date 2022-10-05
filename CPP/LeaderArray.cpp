#include <iostream>
using namespace std;

void leader_array(int arr[],int n, int begin=0){
   
   if (begin==n-1){
    cout<<arr[begin];
    return;
   }
   for(int i=begin; i<n;i++){
     if(arr[begin]<arr[i]){
        break;
    }
     else if(i==n-1 && arr[begin]>>arr[n-1]){
        cout<<arr[begin]<<endl;
     }
   }
   
   leader_array(arr,n,++begin);
}

int main(){
    time_t start, end;
    int arr[7]={7,10,4,3,6,5,2};
    leader_array(arr,7);
}