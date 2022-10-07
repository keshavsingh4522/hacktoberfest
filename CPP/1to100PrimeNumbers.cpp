#include<iostream>
using namespace std;

int main() {

    int i,j;
    bool isPrime;
    for(i = 2; i < 101; i++){
        if(i % 2 == 0){
            if(i == 2){
                isPrime = true;
            }
            else{
                isPrime = false;
            }
        }
        else{
            for(j = 3; j < i; j=j+2){
                if(i % j == 0 && i != 3){
                    isPrime = false;
                    break;
                }
                else{
                    isPrime = true;
                }
            }
        }
        if(isPrime){
            cout<<i<<endl;
        }
    }

    return 0;
}
