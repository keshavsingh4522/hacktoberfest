#include <iostream>
using namespace std;

void printFreq(int arr[], int n){
    int freq = 1, i=1;
    while(i<n){
        while(i<n && arr[i]==arr[i-1]){
            freq++;
            i++;
        }

        cout<<arr[i-1]<<" "<<freq<<endl;

        i++; 
        freq =1;
    }
}

int main(){

    return 0;
}