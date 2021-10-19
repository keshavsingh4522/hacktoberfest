#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// Utility function to find the length of the longest alternating subsequence.
// If `flag` is true, the next element should be greater.
// If `flag` is false, the next element should be smaller.
int util(vector<int> const &A, int start, int end, bool flag)
{
    int result = 0;
    for (int i = start; i <= end; i++)
    {
        // include `A[i]` as next high in subsequence and flip `flag`
        // for next subsequence
        if (flag && A[i - 1] < A[i]) {
            result = max(result, 1 + util(A, i + 1, end, !flag));
        }
 
        // include `A[i]` as next low in subsequence and flip `flag`
        // for next subsequence
        else if (!flag && A[i - 1] > A[i]) {
            result = max(result, 1 + util(A, i + 1, end, !flag));
        }
 
        // don't include `A[i]` in subsequence
        else {
            result = max(result, util(A, i + 1, end, flag));
        }
    }
 
    return result;
}
 
// Function to find the length of the longest subsequence with alternate
// low and high elements. It calls the `util()` method.
int findLongestSequence(vector<int> const &A)
{
    int n = A.size();
 
    // base case
    if (n == 0) {
        return 0;
    }
 
    // Fix the first element and recur for the remaining elements as the first
    // element will always be part of the longest subsequence (why?)
 
    // There are two possibilities:
 
    // 1. The next element is greater (pass true)
    // 2. The next element is smaller (pass false)
    return 1 + max(util(A, 1, n - 1, true), util(A, 1, n - 1, false));
 
    // instead of fixing the first element, we can also directly call
    // return max(util(A, 0, n, true), util(A, 0, n, false));
}
 
int main()
{
    vector<int> A = { 8, 9, 6, 4, 5, 7, 3, 2, 4 };
 
    // Find the longest alternating subsequence
    cout << "The length of the longest alternating subsequence is "
         << findLongestSequence(A);
 
    return 0;
}




