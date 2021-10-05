/*
LEETCODE
198. House Robber
MEDIUM
*/

//SOLUTION
//Dynamic Programming
//Bottom up approach. Start from smallest case i.e for 0 houses, for 1 house..., for 2 houses...
//Now we know that in case of 3 houses, we either rob the ith house and prev to prev one OR rob uptil the prev house depending on whichever is the maximum
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]); //if 3 houses: rob either 1 and 2 OR rob 3, whichever gives max amt
        }
        return dp[n-1];
    }
};
