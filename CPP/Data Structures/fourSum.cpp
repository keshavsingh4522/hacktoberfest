//4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i < n; ++i)
        {
           for(int j=i+1; j<n; ++j)
            {
                int target_2 = target - nums[i] - nums[j];
                int right = j+1;
               int left = n-1;
               while(right < left)
               {
                   int two_sum = nums[right] + nums[left];
                   if(two_sum < target_2) right++;
                   else if(two_sum > target_2)left--;
                   else{
                       vector<int> quadruple(4,0);
                       quadruple[0] = nums[i];
                       quadruple[1] = nums[j];
                       quadruple[2] = nums[right];
                       quadruple[3] = nums[left];
                       res.push_back(quadruple);

                       while(right < left && nums[right] == quadruple[2]) ++right;

                       while(right < left && nums[left] == quadruple[3]) --left;
                   }
               }
                           while((j+1) < n && nums[j+1] == nums[j]) ++j;
            }
             while((i+1) < n && nums[i+1] == nums[i]) ++i;

        }


        return res;
    }

};
