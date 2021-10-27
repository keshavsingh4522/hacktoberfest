/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    if(A==NULL)
    return ans;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty())
    {
        int n=q.size();
        vector<int> level;
        for(int i=0;i<n;i++)
        {
        TreeNode *curr=q.front();
        q.pop();
        if(curr->left)
        q.push(curr->left);
        if(curr->right)
        q.push(curr->right);
        level.push_back(curr->val);
        }
      ans.push_back(level);
    } 
    return ans;
}
