class Solution {
public:
    // we will use kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int current_sum = 0;
        for(int i=0;i<nums.size();i++){
            current_sum += nums[i];
            max_sum = max(max_sum, current_sum);
            current_sum = max(0,current_sum);
        }
        return max_sum;
    }
};