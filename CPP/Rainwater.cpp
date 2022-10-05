#include <iostream>
using namespace std;

int rainwater(int arr[],int n){
    int hcf;
    int water_units=0;
    (arr[n-1]>arr[0])?hcf=arr[0]:hcf=arr[n-1];
    for(int i=1; i<n-1;i++){
        water_units += hcf-arr[i];
        if(water_units<0) water_units=0;
    }
    return water_units;


}


int main(){
int arr[5]={5,5,6,6,6,};
int n=sizeof(arr)/4;
cout<<rainwater( arr, n);
}