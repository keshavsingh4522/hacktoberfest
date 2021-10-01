import java.util.*;

public class BinarySearch {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		//sorted array in ascending order
		int[] arr = {2, 3, 4, 5, 9, 19, 44, 56, 88, 90, 99};
		int target = 44;
		int ans = binarySearch(arr, target);
		System.out.println(ans);
	}

	// return the index
	// return -1 if it doesnt exist
	static int binarySearch(int[] arr, int target) {
		int start = 0;
		int end = arr.length - 1;

		while (start <= end) {
			// find the middle element
//			int middle = (start + end) / 2;
			// might be possible that start + end exceeds the range of integer in java
			// hence we came up with this thing

			int middle = start + (end - start) / 2;

			if (target < arr[middle]) {
				end = middle - 1;
			} else if (target > arr[middle]) {
				start = middle + 1;
			} else {
				return middle;
			}
		}
		return -1;
	}

}
