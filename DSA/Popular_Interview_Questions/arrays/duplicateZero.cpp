#include <iostream>
using namespace std;

vector<int> duplicateZero(vector<int> arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            int c = n-1;
            while(i<c){
                arr[c] = arr[c-1];
                c--;
            }
            i++;
        }
        
    }
}

int main(){

    return 0;
}