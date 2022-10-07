int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            int s = 0;
            for(int j=i; j<nums.size(); j++)
            {
                s+=nums[j];
                if(s%k==0)
                {
                    count+=1;
                }
            }
        }
        return count;
    }
