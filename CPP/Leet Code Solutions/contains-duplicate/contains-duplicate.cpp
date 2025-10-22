class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(),nums.end());
        if(nums_set.size()!=nums.size()){
            return true;
        }
        return false;
    }
};