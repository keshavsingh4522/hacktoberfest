class Solution {
public:
    int rec(vector<int>& nums,int idx){
        if(idx>=nums.size())return 0;
        return max(nums[idx]+rec(nums,idx+2),rec(nums,idx+1));
    }
    int rob(vector<int>& nums) {
        return rec(nums,0);
    }
};
