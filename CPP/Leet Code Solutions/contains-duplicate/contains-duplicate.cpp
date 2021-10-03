class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //creating an unordered set that stores the unique values of integer vector nums
        unordered_set<int> nums_set(nums.begin(),nums.end());
        //checking if the size of unordered set is equal to the size of integer vector
        if(nums_set.size()!=nums.size()){
            //if size is same that means there is no duplicate elements present in the vector
            return true;
        }
        //if size is different then the vector is having duplicate elements
        return false;
    }
};
