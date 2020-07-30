/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (34.93%)
 * Likes:    4321
 * Dislikes: 136
 * Total Accepted:    421.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int minElement = *min_element(coins.begin(), coins.end());
        if (amount == 0)
            return 0;
        if (minElement > amount)
            return -1;
        if (minElement == amount)
            return 1;

        vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= amount; i++)
        {
            if (i - coins[n - 1] >= 0 && dp[n - 1][i - coins[n - 1]] != INT_MAX)
            {
                dp[n - 1][i] = 1 + dp[n - 1][i - coins[n - 1]];
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 1; j <= amount; j++)
            {
                dp[i][j] = dp[i + 1][j];
                if (j - coins[i] >= 0 && dp[i][j - coins[i]] != INT_MAX)
                    dp[i][j] = min(dp[i][j], (1 + dp[i][j - coins[i]]));
            }
        }

        if (dp[0][amount] == INT_MAX)
            return -1;
        return dp[0][amount];
    }
};
// @lc code=end
