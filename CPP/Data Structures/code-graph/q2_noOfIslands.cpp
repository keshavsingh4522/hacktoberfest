class Solution
{
public:
    int dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0')
            return 0;
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
        dfs(grid, i + 1, j);
        return 1;
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int cc = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    cc += dfs(grid, i, j);
                }
            }
        }
        return cc;
    }
};