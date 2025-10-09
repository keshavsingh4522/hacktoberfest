public class ArrayMissing {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        int[] count = new int[n * n + 1];
        int repeated = 0, missing = 0;
        
        for (int[] row : grid) {          // Outer loop iterates through each row
            for (int num : row) {         // Inner loop iterates through each number in the current row
                count[num]++;             // Increment the count for the number
                if (count[num] == 2) {    // Check if this number has been seen twice
                    repeated = num;        // If so, assign it to repeated
                }
            }
        }
        
        // Find the missing value
        for (int i = 1; i <= n * n; i++) {
            if (count[i] == 0) { // Identify the missing value
                missing = i;
                break;
            }
        }
        return new int[] { repeated, missing };
    }
    public static void main(String[] args) {
        ArrayMissing solution = new ArrayMissing();
        
        // Example grid input
        int[][] grid = {
            {1, 2, 3},
            {3, 4, 5},
            {6, 1, 3}  // In this grid, '3' is repeated, and '2' is missing
        };

        // Find the repeated and missing values
        int[] result = solution.findMissingAndRepeatedValues(grid);
        System.out.println("Repeated: " + result[0] + ", Missing: " + result[1]);
    }
}

