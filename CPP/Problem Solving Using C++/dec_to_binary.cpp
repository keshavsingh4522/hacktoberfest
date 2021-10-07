#include<iostream>
#include<math.h>
using namespace std;

long int dec_to_bin(int n){
    long int binary=0;
    int remainder,i,flag=1;
    for(i=1;n!=0;i*=10){
        remainder=n%2;
        n/=2;
        binary+=remainder*i;
    }
    return binary;

}
int main(){
    int n;
    cout<<"Enter decimal number: ";
    cin>>n;
    cout<<"The binary number is: "<<dec_to_bin(n);
    return 0;
}
