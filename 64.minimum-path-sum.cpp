/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (53.87%)
 * Likes:    3142
 * Dislikes: 63
 * Total Accepted:    429.8K
 * Total Submissions: 791.2K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
            return 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = n - 2; i >= 0; i--)
        {
            grid[i][m - 1] += grid[i + 1][m - 1];
        }
        for (int i = m - 2; i >= 0; i--)
        {
            grid[n - 1][i] += grid[n - 1][i + 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = m - 2; j >= 0; j--)
            {
                grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
            }
        }
        return grid[0][0];
    }
};
// @lc code=end
