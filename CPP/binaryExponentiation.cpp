#include <bits/stdc++.h>
using namespace std;

/*
 //recursive approach.
long long binpower(long  a ,long  b){
  if(b==0) return 1;
   long long res = binpower(a,b/2);
  if(b&1) return res*res*a;
  return res*res;
}
*/
long long power(long long x, long long n)
{
    long long res = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res = res * x;
        }
        x = x * x;
        n >>= 1; // n/=2;
    }
    return res;
}
int main()
{

    long long x, n;
    cin >> x >> n;
    cout << power(x, n) << endl;
    // cout<<binpower(x,n);

    return 0;
}
