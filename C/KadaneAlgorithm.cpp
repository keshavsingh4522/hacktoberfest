#include <bits/stdc++.h>
using namespace std;
int maxSubArraySum(int arr[], int size)
{
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for(int i=0;i<size;++i)
    {
        max_ending_here = max_ending_here + arr[i];
        if(max_so_far<max_ending_here)
        {
            max_so_far = max_ending_here;
        }
        if(max_ending_here<0)
        {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}
int main ()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;++i)
    {
        cin >> arr[i];
    }
    int max_sum = maxSubArraySum(arr,n);
    cout << max_sum;
    return 0;
}
