class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size()-1;
        while(start<end){
            int sum = numbers[start] + numbers[end];
            if(sum > target){
                end--;
            } else if(sum < target){
                start++;
            } else {
                return vector<int>{start+1, end+1};
            }
        }
        return vector<int>{start+1, end+1};
    }
};