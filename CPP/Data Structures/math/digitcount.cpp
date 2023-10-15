#include<bits/stdc++.h>
using namespace std;
int count(int n) //O(n)
{
    int digicount=0;
    while(n!=0)
    {  
        digicount+=1;
        n=n/10;
    }
    return digicount;

}
//alternative number of digits in N = log10(N) + 1. --->>> O(1)
int main()
{
    cout<<"enter a number";
    int num;
    cin>> num;
    cout<< count(num);
}