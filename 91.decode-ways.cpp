/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.size() == 0)
            return 0;
        if (s.size() == 1 && s[0] == '0')
            return 0;
        if (s.size() == 1)
            return 1;

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        dp[n - 1] = s[n - 1] == '0' ? 0 : 1;
        for (int i = n - 2; i >= 0; i--)
        {
            int num1 = s[i] - '0';
            int num2 = stoi(s.substr(i, 2));
            if (num1 == 0)
            {
                continue;
            }

            dp[i] = dp[i + 1];
            if (num2 < 27)
            {

                dp[i] += dp[i + 2];
            }
        }

        return dp[0];
    }
};
// @lc code=end
