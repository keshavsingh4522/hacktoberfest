// Largest subarray with 0 sum
//
// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.
//
// Example 1:
//
// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5
// Explanation: The largest subarray with
// sum 0 will be -2 2 -8 1 7.
// Your Task:
// You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.
//
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

int maxLen(int A[], int n)
{
    // Your code here
    int sum=0;
    int maxi=0;
    unordered_map<int,int> mpp;
    for(int i=0;i<n;++i)
    {
        sum += A[i];
        if(sum == 0)
        {
            maxi = i + 1;
        }
        else {
            if(mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}
