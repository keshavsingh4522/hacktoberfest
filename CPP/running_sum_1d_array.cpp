using namespace std;
#include <iostream>
#include <vector>

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int sum = 0;
        for(auto val:nums)
        {
            sum += val;
            res.emplace_back(sum);
        }
        return res;
    }
};