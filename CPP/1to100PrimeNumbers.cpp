#include<iostream>
using namespace std;

int main() {
    
    int i,j;

    for(i=2;i<101;i++) {
    bool x=true;
    
    for (j=2;j<(i-1);j++) {

    if(i%j==0) {
        x=false;
        break;
    }

    }

    if(x==true) {
        cout<<i<<endl;
    }

    }

    return 0;
}