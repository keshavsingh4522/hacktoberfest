//Starters 8
//PENALTY 

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

#define pi 3.14159265358979323846
using namespace std;


bool comp(int a , int b){
    return (a < b);
}

void solve(){
    int a,b,c,d,e,f,g,h,i,j;
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;

    if((a+c+e+g+i)> (b+d+f+h+j)){
        cout << "1" <<endl;
    }
    else if((a+c+e+g+i)< (b+d+f+h+j)){
        cout << "2" <<endl;
    }
    else cout << "0" <<endl;

}

int main(){
    int t;
    cin>> t;

    while(t--){
        solve();
    }
    return 0;
}