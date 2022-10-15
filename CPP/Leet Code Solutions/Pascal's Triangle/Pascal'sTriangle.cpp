class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1);
        if(numRows==1)
            return ans;
        ans[1].push_back(1);        
        ans[1].push_back(1);
        if(numRows==2)
            return ans;
        for(int i=2;i<numRows;i++){
            for(int j=0;j<=i;j++){
                if(j==0 or j==i)
                    ans[i].push_back(1);
                else
                    ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
        }
        return ans;
    }
};
 
