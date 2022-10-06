#include<bits/stdc++.h>
using namespace std;

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int main(){
  int x = 12, y = 5;
  int hcf = gcd(x, y);
  cout << hcf ;
  return 0;
}
