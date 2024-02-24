/*
    https://leetcode.com/problems/maximum-earnings-from-taxi/

    DP weighted job schedule problem

*/
class Solution {
public:
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        
        
        sort(rides.begin(), rides.end(),[&](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
 
        
        int N=rides.size();
        
        long long dp[N];
        dp[0]=rides[0][2]+rides[0][1]-rides[0][0];
        
        for(int i=1;i<N ;i++){
            long long incusive=rides[i][2]+rides[i][1]-rides[i][0];
            int L=0,R=i-1,mid,idx=-1;
            
            while(L<=R){
                mid=L+(R-L)/2;
                if(rides[mid][1] <=rides[i][0]){
                    L=mid+1;
                    idx=mid;
                }
                else R=mid-1;
            }
            
            if(idx!=-1){
                
                incusive+=dp[idx];
                
            }
            dp[i]=max(dp[i-1],incusive);
        }
        
        return dp[N-1];
    }
};