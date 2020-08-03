/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (46.49%)
 * Likes:    3052
 * Dislikes: 189
 * Total Accepted:    316K
 * Total Submissions: 668.8K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        if (n == 3)
            return 3;

        if (n == 4)
            return 1;

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        dp[4] = 1;

        for (int i = 5; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                if (i - j * j >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - (j * j)]);
            }
        }
        return dp[n];
    }
};
// @lc code=end
