#include <iostream>
using namespace std;

// Sort array then search == complexity of nlogn 
// better soln exists

void frequency(int arr[], int n){
   for(int i=0;i<n;i++){
      int count=0;
      if(arr[i+1]==arr[i]){
        continue;
      }
      for(int j=0;j<n;j++){
        if(arr[i]==arr[j]) count++;
   }
    cout<<"Frequency of "<<arr[i]<<" : "<<count<<endl;
}
}

int main(){
int arr[6]={1,2,2,3,3,3};
frequency(arr,6);


}