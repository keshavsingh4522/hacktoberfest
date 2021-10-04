/*
Given an array, rotate the array to the right by k steps, where k is non-negative.
Example:
        [1,2,3,4,5,6,7] , k = 3 => [5,6,7,1,2,3,4]
        [-1,-100,3,99], k = 2 => [3,99,-1,-100]
*/
class ArrayRotation {
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        if (k == 0) return; // Rotated array will be same as original array
        reverse(0, nums.length-1, nums);
        reverse(0, k-1, nums);
        reverse(k, nums.length-1, nums);
    }
    
    private void reverse(int start, int end, int[] nums){        
        while(start < end){
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }
}
