#include <iostream>
using namespace std;

int countsubsets(int arr[],int n, int sum){
if(n==0) {
if(sum==0) return 1;
else return 0;
}
return countsubsets(arr,n-1,sum) + countsubsets(arr,n-1,sum-arr[n]);
}



int main(){
int arr[4]={10,5,25,20};
cout<<countsubsets(arr,4,25);


}