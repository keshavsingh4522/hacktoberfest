#include <bits/stdc++.h>
using namespace std;
int dp[20001][20001];

int countSubsets(int arr[], int n, int sum)
{
	if (dp[n][sum] != -1)
		return dp[n][sum];
	// base case
	if (sum == 0)
		return 1;
	if (n == 0)
		return 0;
	if (arr[n - 1] <= sum)
		return dp[n][sum] = countSubsets(arr, n - 1, sum - arr[n - 1]) + countSubsets(arr, n - 1, sum);
		
	return dp[n][sum] = countSubsets(arr, n - 1, sum);
}

int subsetsDiff(int arr[], int n, int diff)
{
	int arr_sum = 0;
	// sum of the array
	for (int i = 0; i < n; i++)
		arr_sum += arr[i];
    /*
    Let there be two subsets with sum s1 and s2 respectively
	s1 + s2 = arr_sum
	s1 - s2 = diff
	so solving the above equations, we get:
	s1 = (diff + arr_sum)/2
	Therefore, we will find number of subsets with sum as s1
    */
	int sum = (diff + arr_sum) / 2;
	
	return countSubsets(arr, n, sum);
}

int main()
{
	// dp table
	memset(dp, -1, sizeof(dp));
	int n, diff; 
	cin >> n >> diff;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << subsetsDiff(arr, n, diff);
	
	return 0;
}
