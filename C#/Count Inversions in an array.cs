// C# program to count inversions
// in an array
using System;
using System.Collections.Generic;

class GFG {

	static int[] arr = new int[] { 1, 20, 6, 4, 5 };

	static int getInvCount(int n)
	{
		int inv_count = 0;

		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (arr[i] > arr[j])
					inv_count++;

		return inv_count;
	}

	// Driver code
	public static void Main()
	{
		Console.WriteLine("Number of "
						+ "inversions are "
						+ getInvCount(arr.Length));
	}
}

// This code is contributed by Sam007
