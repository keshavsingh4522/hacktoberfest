// Sort elements by frequency. If two elements have same
// count, then put the elements that appears first
#include <bits/stdc++.h>
using namespace std;

// Used for sorting
struct ele {
	int count, index, val;
};

// Used for sorting by value
bool mycomp(struct ele a, struct ele b)
{
	return (a.val < b.val);
}

// Used for sorting by frequency. And if frequency is same,
// then by appearance
bool mycomp2(struct ele a, struct ele b)
{
	if (a.count != b.count)
		return (a.count < b.count);
	else
		return a.index > b.index;
}

void sortByFrequency(int arr[], int n)
{
	struct ele element[n];
	for (int i = 0; i < n; i++) {

		// Fill Indexes
		element[i].index = i;

		// Initialize counts as 0
		element[i].count = 0;

		// Fill values in structure
		// elements
		element[i].val = arr[i];
	}

	/* Sort the structure elements according to value,
	we used stable sort so relative order is maintained.
	*/
	stable_sort(element, element + n, mycomp);

	/* initialize count of first element as 1 */
	element[0].count = 1;

	/* Count occurrences of remaining elements */
	for (int i = 1; i < n; i++) {

		if (element[i].val == element[i - 1].val) {
			element[i].count += element[i - 1].count + 1;

			/* Set count of previous element as -1, we are
			doing this because we'll again sort on the
			basis of counts (if counts are equal than on
			the basis of index)*/
			element[i - 1].count = -1;

			/* Retain the first index (Remember first index
			is always present in the first duplicate we
			used stable sort. */
			element[i].index = element[i - 1].index;
		}

		/* Else If previous element is not equal to current
		so set the count to 1 */
		else
			element[i].count = 1;
	}

	/* Now we have counts and first index for each element
	so now sort on the basis of count and in case of tie
	use index to sort.*/
	stable_sort(element, element + n, mycomp2);
	for (int i = n - 1, index = 0; i >= 0; i--)
		if (element[i].count != -1)
			for (int j = 0; j < element[i].count; j++)
				arr[index++] = element[i].val;
}

// Driver program
int main()
{
	int arr[] = { 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sortByFrequency(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
