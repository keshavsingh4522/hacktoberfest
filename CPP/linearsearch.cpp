#include<iostream>
using namespace std;
int main(){
int n,temp,c;
cout<<"Enter the number of elements :\n";
cin>>n;
cout<<"Enter the number for searching :\n";
cin>>temp;
int A[n];
cout<<"Enter the elements :\n";
for(int i=0;i<n;i++)
cin>>A[i];
for(int i=0;i<n;i++){
    if(A[i]==temp)
    cout<<"Number "<<temp<<" found at index "<<i;
    else
    c++;
}
if(c==n-1){
    cout<<"Number not found";
}
return 0;
}
