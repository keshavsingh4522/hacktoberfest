// C++ program to find maximum average subarray
// of given length.
#include<bits/stdc++.h>
using namespace std;

// Returns beginning index of maximum average
// subarray of length 'k'
int findMaxAverage(int arr[], int n, int k)
{
	// Check if 'k' is valid
	if (k > n)
		return -1;

	// Create and fill array to store cumulative
	// sum. csum[i] stores sum of arr[0] to arr[i]
	int *csum = new int[n];
	csum[0] = arr[0];
	for (int i=1; i<n; i++)
	csum[i] = csum[i-1] + arr[i];

	// Initialize max_sm as sum of first subarray
	int max_sum = csum[k-1], max_end = k-1;

	// Find sum of other subarrays and update
	// max_sum if required.
	for (int i=k; i<n; i++)
	{
		int curr_sum = csum[i] - csum[i-k];
		if (curr_sum > max_sum)
		{
			max_sum = curr_sum;
			max_end = i;
		}
	}

	delete [] csum; // To avoid memory leak

	// Return starting index
	return max_end - k + 1;
}

// Driver program
int main()
{
	int arr[] = {1, 12, -5, -6, 50, 3};
	int k = 4;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "The maximum average subarray of "
		"length "<< k << " begins at index "
		<< findMaxAverage(arr, n, k);
	return 0;
}
