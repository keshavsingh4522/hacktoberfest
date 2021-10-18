#include<iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int a[n];
    
    cout<<"Enter the array";
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    sort(a,a+n);
    int k;
    cout<<"Enter the value of 'k' ";
    cin>>k;
    cout<<a[k-1];

    return 0;
}