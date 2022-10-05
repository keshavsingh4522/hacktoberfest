#include <iostream>
using namespace std;

int* margining(int arr[],int n , int count =0){
   for(int i=0;i<n;i++){
     if(arr[i]!=0){
       int temp=arr[count];
       arr[count]=arr[i];
       arr[i]=temp;
       count++;
    }
   }
   return arr;
}

int main(){
int arr[5]={1,0,2,0,3};
int n=sizeof(arr)/sizeof(arr[0]);
int *arr1;
arr1=margining(arr,n);
for(int i=0;i<n;i++){
    cout<<arr[i];
}
cout<<endl;
string s1;
for(int i:arr){
    s1+=to_string(i);
}
cout<<s1;
}