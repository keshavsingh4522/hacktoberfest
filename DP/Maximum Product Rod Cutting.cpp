
#include <iostream>
#include <algorithm>
using namespace std;
 
// Function to find the best way to cut a rod of length `n`
// where the rod of length `i` has price `i`
int findMaxProfit(int n)
{
    // base case
    if (n <= 1) {
        return n;
    }
 
    // rod of length `n` has at least cost of `n`
    int maxValue = n;
 
    // one by one, partition the given rod of length `n` into two parts of
    // length (1, n-1), (2, n-2), … (n-1 , 1), (n, 0) and take maximum
    for (int i = 1; i <= n; i++) {
        maxValue = max(maxValue, i * findMaxProfit(n - i));
    }
 
    return maxValue;
}
 
int main()
{
    // `n` is rod length
    int n = 15;        // 3 × 5 times
 
    cout << "The Maximum profit is " << findMaxProfit(n);
 
    return 0;
}


