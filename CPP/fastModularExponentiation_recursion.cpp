#include<iostream>
using namespace std;

int fasExpo(int a, int n, int mod)
{
    // base condition
    if(n == 0)
        return 1;

    //  a ^ n % mod

    if(n % 2 == 0)
       // a ^ n = ((a ^ 2) ^ (n / 2)) 
       return fasExpo((1LL * a * a) % mod, n / 2, mod);
    
    // since if statement is a return statement logically there's no need to write a else statement.
    // Therefore for the odd case it'll be a default return statement.

    // a ^ n = a * (a ^ (n - 1))
    return (1LL * a * fasExpo(a , n - 1, mod)) % mod;

}

int main()
{
    cout << fasExpo(2, 10, 10000000007);
    return 0;
}