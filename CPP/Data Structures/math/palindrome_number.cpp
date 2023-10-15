#include<bits/stdc++.h>
using namespace std;
bool palindrome(long  n)
{
    long  rev=0;
    long  temp=n;
    while(temp!=0)
    {
        long  last_digit=temp%10;
        rev=rev*10+last_digit;
        temp/=10;
    }
    return(rev==n) ;
}
int main()
{
    long  x;
    cout<<"enter the number";
    cin>>x;
    cout<<palindrome(x);
}