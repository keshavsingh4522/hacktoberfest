class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> all_nums;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                all_nums.push_back(matrix[i][j]);
            }
        }
        sort(all_nums.begin(),all_nums.end());
        return all_nums[k-1];
    }
};