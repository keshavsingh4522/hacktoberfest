/*
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
 */

public class numBinarySearch {
    public int search(int[] nums, int target) {
        int index = -1;
        int start = 0, end = nums.length-1, middle = (start+end)/2;
        while(start <= end){
            if(nums[middle] == target) return middle;
            if(nums[middle] > target){
                end = middle - 1;
                middle = (end+start)/2;
            }
            if(nums[middle] < target){
                start = middle + 1;
                middle=(start+end)/2;
            }
        }
        return index;
    }
}
