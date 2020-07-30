/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (31.08%)
 * Likes:    1443
 * Dislikes: 87
 * Total Accepted:    155.3K
 * Total Submissions: 494.3K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size();
        int m = s2.size();
        if (m == 0)
            return s1 == s3;

        if (n == 0)
            return s2 == s3;
        if (s3.size() != m + n)
            return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = (s3[i - 1] == s1[i - 1]) && dp[i - 1][0];
        }

        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = (s3[j - 1] == s2[j - 1]) && dp[0][j - 1];
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[(i + j) - 1])
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else if (s1[i - 1] == s3[(i + j) - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else if (s2[j - 1] == s3[(i + j) - 1])
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[n][m];
    }
};
// @lc code=end
