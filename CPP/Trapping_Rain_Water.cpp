// Trapping Rain Water

#include <bits/stdc++.h>
using namespace std;

// TC : O(n^2) Sc: O(1)
// int trap_water(int heights[], int n) {
// 	int result = 0;

// 	for (int i = 0; i < n; ++i)
// 	{
// 		int left_max = heights[0];
// 		for (int l = 1; l <= i; l++)
// 			left_max = max(left_max, heights[l]);

// 		int right_max = heights[n - 1];
// 		for (int r = n - 2; r >= i; r--)
// 			right_max = max(right_max, heights[r]);

// 		result += min(left_max, right_max) - heights[i];
// 	}
// 	return result;
// }


// TC: O(n)  SC: O(2n)
// int trap_water(int heights[], int n) {
// 	int result = 0;

// 	int prefix_max[n], l = 0, max = heights[0];

// 	for (int i = 0; i < n; i++) {
// 		if (heights[i] > max)
// 			max = heights[i];
// 		prefix_max[l++] = max;
// 	}

// 	int suffix_max[n], r = n - 1;
// 	max = heights[n - 1];

// 	for (int i = n - 1; i >= 0; i--) {
// 		if (heights[i] > max)
// 			max = heights[i];
// 		suffix_max[r--] = max;
// 	}

// 	for (int i = 0; i < n; i++)
// 		result += min(prefix_max[i] , suffix_max[i]) - heights[i];

// 	return result;
// }

// TC: O(n)  SC: O(1)
int trap_water(int heights[], int n) {
	int result = 0, l = 0, r = n - 1;
	int left_max = 0, right_max = 0;

	while (l <= r) {
		if (heights[l] <= heights[r]) {
			if (heights[l] > left_max)
				left_max = heights[l];
			else
				result += left_max - heights[l];
			l++;
		}
		else {
			if (heights[r] > right_max)
				right_max = heights[r];
			else
				result += right_max - heights[r];
			r--;
		}
	}
	return result;
}

int main() {
	int n; cin >> n;

	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int result = trap_water(arr, n);
	cout << "\nResult : " << result;
}
