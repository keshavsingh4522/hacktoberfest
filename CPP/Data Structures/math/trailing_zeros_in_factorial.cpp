/*#include<bits/stdc++.h>
using namespace std;
long long count_zero(long long n)
{
    long long count =0;
    while(n)
    {
        long long last_digit=n%10;
        if(last_digit==0)
        count++;
        n/=10;
    }
    return count;
}
long long factorial(long long n)
{
    long long fac=1;
    for(long long i=1;i<=n;i++)
    {
        fac*=i;
    }
    cout<<fac<<endl;
    return count_zero(fac);
}

int main()
{
    long long n=60;
    cout<<factorial(n);
}
wont work because of overflow 
*/
#include<bits/stdc++.h>
using namespace std; 
int count_trailing_zero(int n)
{
    int res=0;
    for(int i=5;i<=n;i=i*5)
    // every 5 and 2 pair will result in a zero since no of five will be always less we are taking that into account 
    {
        res=res+n/i;
    }
    return res;
}
int main()
{
    int n=4;// number for which you need to find the trailing zero in its factorial
    cout<<count_trailing_zero(n);
}
