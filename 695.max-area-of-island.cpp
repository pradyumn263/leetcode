/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution
{
public:
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size())
            return 0;
        if (visited[i][j])
            return 0;
        if (!grid[i][j])
            return 0;
        int res = 0;
        visited[i][j] = true;
        res += dfs(grid, visited, i + 1, j) + dfs(grid, visited, i - 1, j) + dfs(grid, visited, i, j + 1) + dfs(grid, visited, i, j - 1);
        return res + grid[i][j];
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int res = 0;
        if (grid.size() == 0)
            return res;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j])
                    res = max(res, dfs(grid, visited, i, j));
            }
        }
        return res;
    }
};
// @lc code=end
