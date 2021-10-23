#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

#define pi 3.14159265358979323846
using namespace std;

void solve(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c;
    // cout<<endl;
    cin>>d>>e>>f;
    
    if((a+b+c)==(d+e+f)){
        cout<< "Pass" <<endl;
    }
    else
        cout << "Fail" << endl;
}

int main(){
    int t;
    cin>> t;

    while(t--){
        solve();
    }
    return 0;
}