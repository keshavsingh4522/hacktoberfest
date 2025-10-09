public class ArrayMerge {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // Pointers for nums1, nums2, and the end of the merged array
        int i = m - 1; // Pointer for nums1's last element
        int j = n - 1; // Pointer for nums2's last element
        int k = m + n - 1; // Pointer for the last position in nums1

        // Merge in reverse order
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i]; // Place larger value at the end
                i--;
            } else {
                nums1[k] = nums2[j]; // Place larger value at the end
                j--;
            }
            k--; // Move to the next position
        }

        // If there are remaining elements in nums2, copy them over
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }

        // No need to copy remaining elements from nums1 as they are already in place
    }

    public static void main(String[] args) {
        ArrayMerge solution = new ArrayMerge();

        // Test case
        int[] nums1 = {1, 2, 3, 0, 0, 0}; // nums1 with enough space for nums2
        int m = 3; // Number of initialized elements in nums1
        int[] nums2 = {2, 5, 6}; // nums2 array
        int n = 3; // Number of initialized elements in nums2

        // Merge nums1 and nums2
        solution.merge(nums1, m, nums2, n);

        // Output the merged array
        System.out.print("Merged array: ");
        for (int num : nums1) {
            System.out.print(num + " ");
        }
    }
}
