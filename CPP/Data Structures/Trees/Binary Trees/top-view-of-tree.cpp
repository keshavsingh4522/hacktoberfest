//Note : If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A)
{
    map<int, vector<int>> mp;

    int hd = 0;
    vector<vector<int>> v;

    if (!A)
        return vector<vector<int>>();

    queue<pair<TreeNode*, int> > que;
    que.push(make_pair(A, hd));

    while (!que.empty())
    {
        pair<TreeNode *,int> temp = que.front();
        que.pop();
        hd = temp.second;
        TreeNode* node = temp.first;

        mp[hd].push_back(node->val);

        if (node->left)
            que.push(make_pair(node->left, hd-1));
        if (node->right)
            que.push(make_pair(node->right, hd+1));
    }

    for(auto it : mp)
    {
        v.push_back(it.second);
    }

    return v;
}