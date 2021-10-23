#include<iostream>
using namespace std;

int main(){
  
    cout<<"Enter size\n";
    int n,temp;
    cin>>n;

    cout<<"Enter array\n";
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    for(int i=0;i<n;i++){
        if(i==0){
            temp=a[0];
            a[0]=a[n-1];
        }
        else{
            temp=a[i]+temp;
            a[i]=temp-a[i];
            temp=temp-a[i];
        }
    }

    for(int i=0;i<n;i++)
    cout<<a[i];

    return 0;
}