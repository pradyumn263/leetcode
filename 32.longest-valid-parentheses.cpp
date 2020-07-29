/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        if (n <= 1)
            return 0;

        vector<int> dp(n, 0);
        int i = 1;
        int ans = 0;
        for (i = 1; i < n; i++)
        {
            if (s[i] == '(')
            {
                continue;
            }
            int plen = dp[i - 1];
            if (i - plen - 1 < 0)
                continue;
            if (s[i - plen - 1] == ')')
                continue;

            dp[i] = dp[i - 1] + 2;
            if (i - plen - 2 >= 0)
                dp[i] += dp[i - plen - 2];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end
