public class slidingwindow {
    // Java code here
// O(n*k) solution for finding
// maximum sum of a subarray
// of size k
    class GFG {
        // Returns maximum sum in
        // a subarray of size k.
        static int maxSum(int arr[], int n, int k)
        {
            // Initialize result
            int max_sum = Integer.MIN_VALUE;

            // Consider all blocks starting with i.
            for (int i = 0; i < n - k + 1; i++) {
                int current_sum = 0;
                for (int j = 0; j < k; j++)
                    current_sum = current_sum + arr[i + j];

                // Update result if required.
                max_sum = Math.max(current_sum, max_sum);
            }

            return max_sum;
        }

        // Driver code
        public static void main(String[] args)
        {
            int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
            int k = 4;
            int n = arr.length;
            System.out.println(maxSum(arr, n, k));
        }
    }
}
