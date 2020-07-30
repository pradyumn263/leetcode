/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == m - 1)
                {
                    dp[i][j] = max(1, 1 - nums[i][j]);
                }

                if (i + 1 < n)
                {
                    dp[i][j] = max(1, dp[i + 1][j] - nums[i][j]);
                }

                if (j + 1 < m)
                {
                    dp[i][j] = min(dp[i][j], max(1, dp[i][j + 1] - nums[i][j]));
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end
