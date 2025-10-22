#include<bits/stdc++.h>
using namespace std;
int gcdfn(int a, int b)
{
    if(b==0)
    return a;
    else
    return gcdfn(b,a%b);

}
int main()
{
    int a =15, b=12;
    cout<<gcdfn(a,b);
}