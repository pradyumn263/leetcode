/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.28%)
 * Likes:    7238
 * Dislikes: 550
 * Total Accepted:    969K
 * Total Submissions: 3.3M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string &s)
    {
        if (s.size() <= 1)
            return s;

        int startIndex = 0;
        int len = 1;

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (j == i + 1)
                    {
                        dp[i][j] = 2;
                    }
                    else
                    {
                        if (dp[i + 1][j - 1])
                            dp[i][j] = dp[i + 1][j - 1] + 2;
                    }

                    if (len < dp[i][j])
                    {
                        len = dp[i][j];
                        startIndex = i;
                    }
                }
            }
        }

        return s.substr(startIndex, len);
    }
};
// @lc code=end
