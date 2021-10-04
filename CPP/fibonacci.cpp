//can caluculate upto 1477th fibonacci number which have 309 digits
#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter which fibonacci number you want as your output: ";
    cin>>size;
    long double store[size];
    store[0]=0;
    store[1]=1;
    for(int i=2;i<size;i++){
        store[i]=store[i-1]+store[i-2];
    }
    cout<<"The "<<size<<"'th fibonaaci number is : "<<store[size-1]<<endl;
    return 0;
}

