// C++ code to implement factorial
#include <bits/stdc++.h>
using namespace std;
 
// Factorial function
int f(int n)
{
    // Stop condition
    if (n == 0 || n == 1)
        return 1;
 
    // Recursive condition
    else
        return n * f(n - 1);
}
 
// Driver code
int main()
{
    int n = 5;
    cout<<"factorial of "<<n<<" is: "<<f(n);
    return 0;
}