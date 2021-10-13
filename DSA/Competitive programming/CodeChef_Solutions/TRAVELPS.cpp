//TRAVELPS

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

#define pi 3.14159265358979323846
using namespace std;


void solve(){
    int n,a,b;
    string s;
    cin>>n>>a>>b;
    cin>>s;
    int c1=0,c2=0;
    
    
    for(int i=0;i<n;i++){
        if(s.at(i)=='0'){
            c1++;
        }
        else if(s.at(i)=='1'){
            c2++;
        }
    }
    cout<< (c2*b)+(c1*a)<<endl;
    
}

int main(){
    int t;
    cin>> t;

    while(t--){
        solve();
    }
    return 0;
}