class Solution {
    public int[] twoSum(int[] nums, int target) {
        int [] answerIndex = new int[2];
        int c = 0;
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                if(nums[i]+nums[j]==target){
                    answerIndex[c] = i;
                    c++;
                    answerIndex[c] = j;
                }
            }
        }
        return answerIndex;
    }
}