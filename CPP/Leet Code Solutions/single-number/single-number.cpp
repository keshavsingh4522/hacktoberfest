class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        set<int> nums_set(nums.begin(), nums.end());
        int set_sum = 0;
        int total_sum = 0;
        for(int x:nums_set){
            set_sum += x;
        }
        for(int x:nums){
            total_sum += x;
        }
        int single_num = 2*set_sum - total_sum;
        return single_num;
        
    }
};