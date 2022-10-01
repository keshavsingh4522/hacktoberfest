// Introduction about this searching algo

/*

Interpolation search algo was first described by W. W. Peterson in 1957.
Average-case : O(log(log(n)))
Best-case : O(1)
Worst-case : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

int interpolation_search(int arr[], int low, int high, int x)
{
	int position;
	
	if (low <= high && x >= arr[low] && x <= arr[high]) 
	{
		position = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

		if (arr[position] == x)return position;

		if (arr[position] < x)return interpolation_search(arr, position + 1, high, x);
		
		if (arr[position] > x)return interpolation_search(arr, low, position - 1, x);
	}
	return -1;
}

int main()
{

	int arr[] = { 3, 7, 11, 12, 17, 19, 22, 24, 25, 31, 31, 38, 45, 47 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 31;
	
	int index = interpolation_search(arr, 0, n - 1, x);

	if (index != -1) cout << "Element found at index " << index;
	else cout << "Element not found, Try again with different element.";

	return 0;
}
