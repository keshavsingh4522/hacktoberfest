#include <iostream>
using namespace std;

int max1s(int arr[], int n){
    int count=0, final_count;
    for(int i=0;i<n;i++){
      if(arr[i]==1) count++;
      else {
        if(count>final_count)final_count=count;  
        count=0;
        }
      
}

return final_count;
}


int main(){
int arr[9]={1,0,1,1,1,1,0,1,1};
int n=sizeof(arr)/4;
cout<<max1s(arr,n);
}