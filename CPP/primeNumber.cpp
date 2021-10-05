/* --logic--
brute force method : O(n)

    searching for a divisor from 2 to n-1 through a loop

optimized method : O(sqrt(n))
    
    any number n which is not a prime can be written as 'n = a * b' where aE[2, n-1], hence b = n /a
    n = a * b 
    -> b = n / a
    -> a <= b
    -> a * b >= a * a
    -> n >= a * a
    -> a <= sqrt(n)

*/

#include <cmath>
#include<iostream>
using namespace std;

bool isPrime(int n)
{
    if(n <= 1)
        return false;
    

    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }

    return true;

}

int main()
{
    int n;
    cin >> n;

    cout << boolalpha << isPrime(n) << endl;

    return 0;
}