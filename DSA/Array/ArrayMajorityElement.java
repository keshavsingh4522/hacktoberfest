import java.util.*;
public class ArrayMajorityElement {
    public static int majorityElement(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        return nums[n / 2];
    }
public static void main(String[] args) {
    int[] nums = {3, 2, 3, 1, 1, 1};
    System.out.println("Majority element in nums : " + majorityElement(nums));
    }
}
