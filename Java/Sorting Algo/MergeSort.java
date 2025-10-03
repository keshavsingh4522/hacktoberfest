import java.util.Arrays;

public class MergeSort {
  
    public static void mergeSort(int[] arr) {
        if (arr == null || arr.length <= 1) {
            return; // Base case: array is already sorted or empty
        }
        int[] temp = new int[arr.length]; // Temporary array for merging
        mergeSort(arr, temp, 0, arr.length - 1);
    }

    // Recursive helper function for merge sort
    private static void mergeSort(int[] arr, int[] temp, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2; // Calculate middle index
            mergeSort(arr, temp, left, mid); // Sort left half
            mergeSort(arr, temp, mid + 1, right); // Sort right half
            merge(arr, temp, left, mid, right); // Merge the sorted halves
        }
    }

    // Merges two sorted subarrays into a single sorted array
    private static void merge(int[] arr, int[] temp, int left, int mid, int right) {
        // Copy elements to temporary array
        for (int i = left; i <= right; i++) {
            temp[i] = arr[i];
        }

        int i = left;       // Pointer for the left subarray
        int j = mid + 1;    // Pointer for the right subarray
        int k = left;       // Pointer for the main array

        // Merge elements back into the original array
        while (i <= mid && j <= right) {
            if (temp[i] <= temp[j]) {
                arr[k] = temp[i];
                i++;
            } else {
                arr[k] = temp[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of the left subarray, if any
        while (i <= mid) {
            arr[k] = temp[i];
            i++;
            k++;
        }

        // Copy remaining elements of the right subarray, if any 
        while (j <= right) {
           arr[k] = temp[j];
             j++;
             k++;
        }
    }

    public static void main(String[] args) {
        int[] data = {12, 11, 13, 5, 6, 7};
        System.out.println("Original array: " + Arrays.toString(data));
        mergeSort(data);
        System.out.println("Sorted array: " + Arrays.toString(data));

        int[] data2 = {38, 27, 43, 3, 9, 82, 10};
        System.out.println("Original array: " + Arrays.toString(data2));
        mergeSort(data2);
        System.out.println("Sorted array: " + Arrays.toString(data2));
    }
}
