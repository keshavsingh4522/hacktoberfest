
//solution for 1672. Richest Customer Wealth
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mw = INT_MIN;
        for(int i = 0; i < accounts.size(); i++){
            int s = 0;
            for(int j = 0; j < accounts[i].size(); j++){
                s += accounts[i][j];
            }
            mw = max(mw,s);
        }
        return mw;        
    }
};