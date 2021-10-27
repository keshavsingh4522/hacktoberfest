/*
Problem Link- https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
*/
class Solution
{
public:
    int dir[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    char c[4] = {'D', 'L', 'R', 'U'};

    void findPathUtil(int i, int j, vector<vector<int>> &a, int n, string s, vector<string> &ans, vector<vector<int>> &vis)
    {

        if (i >= n || j >= n || i < 0 || j < 0 || a[i][j] == 0 || vis[i][j])
            return;

        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(s);
            return;
        }

        for (int k = 0; k < 4; k++)
        {
            s += c[k];
            vis[i][j] = 1;
            findPathUtil(i + dir[k][0], j + dir[k][1], a, n, s, ans, vis);
            s.pop_back();
            vis[i][j] = 0;
        }

        return;
    }

    vector<string> findPath(vector<vector<int>> &a, int n)
    {

        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        // memset(vis,0,sizeof(int));
        string s = "";
        findPathUtil(0, 0, a, n, s, ans, vis);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};
