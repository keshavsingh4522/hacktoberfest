import java.util.Arrays;
import java.util.LinkedList;

public class ArrayMergeIntervals {
    
    public int[][] merge(int[][] intervals) {
        // Sort intervals by start time
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        // Use a LinkedList to store the merged intervals
        LinkedList<int[]> merged = new LinkedList<>();

        // Iterate over all intervals
        for (int[] interval : intervals) {
            // If the list of merged intervals is empty or if the current interval does not overlap
            // with the previous one, simply add it.
            if (merged.isEmpty() || merged.getLast()[1] < interval[0]) {
                merged.add(interval);
            } else {
                // Otherwise, there is overlap, so merge the current interval with the previous one.
                merged.getLast()[1] = Math.max(merged.getLast()[1], interval[1]);
            }
        }

        // Convert the LinkedList to a 2D array before returning
        return merged.toArray(new int[merged.size()][]);
    }

    public static void main(String[] args) {
        ArrayMergeIntervals mi = new ArrayMergeIntervals();
        
        int[][] intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        int[][] result = mi.merge(intervals);
        
        System.out.println("Merged Intervals: ");
        for (int[] interval : result) {
            System.out.println(Arrays.toString(interval));
        }
    }
}
