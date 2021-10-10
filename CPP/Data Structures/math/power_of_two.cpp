// check given number can be represented in power of two
// fact: in binary only one bit is set if the number can represented by 2
//use brian algo to unset the last bit and check its zero or not
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=16;
    if((n&(n-1))==0)
    cout<<"yes";
    else 
    cout<<"no";
}