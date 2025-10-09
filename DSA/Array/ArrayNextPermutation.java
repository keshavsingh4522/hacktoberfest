public class ArrayNextPermutation {

    // Function to find the next permutation
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int i = n - 2;

        // Step 1: Find the first decreasing element from the end
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If such an element was found, find the next greater element
        if (i >= 0) {
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            // Step 3: Swap the elements
            swap(nums, i, j);
        }

        // Step 4: Reverse the part of the array after the swapped element
        reverse(nums, i + 1, n - 1);
    }

    // Helper function to swap two elements in the array
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Helper function to reverse a part of the array
    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
    }

    // Main function to test the algorithm
    public static void main(String[] args) {
        ArrayNextPermutation np = new ArrayNextPermutation();

        // Test case 1: Find next permutation of [1, 2, 3]
        int[] nums1 = {1, 2, 3};
        np.nextPermutation(nums1);
        System.out.print("Next permutation of [1, 2, 3]: ");
        for (int num : nums1) {
            System.out.print(num + " ");
        }
        System.out.println();

        // Test case 2: Find next permutation of [3, 2, 1]
        int[] nums2 = {3, 2, 1};
        np.nextPermutation(nums2);
        System.out.print("Next permutation of [3, 2, 1]: ");
        for (int num : nums2) {
            System.out.print(num + " ");
        }
        System.out.println();

        // Test case 3: Find next permutation of [1, 1, 5]
        int[] nums3 = {1, 1, 5};
        np.nextPermutation(nums3);
        System.out.print("Next permutation of [1, 1, 5]: ");
        for (int num : nums3) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
