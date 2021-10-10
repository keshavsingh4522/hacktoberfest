class Solution {
public:
    int minCost(int Len, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(Len);
        sort(cuts.begin(),cuts.end());
        
        int n=cuts.size();
        int dp[n][n];
        for(int gap=1;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==1){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=2e9;
                    for(int k=i+1;k<j;k++){
                        dp[i][j]=min(dp[i][j],cuts[j]-cuts[i]+dp[i][k]+dp[k][j]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};