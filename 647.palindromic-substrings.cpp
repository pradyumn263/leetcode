/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (60.20%)
 * Likes:    2705
 * Dislikes: 115
 * Total Accepted:    190.2K
 * Total Submissions: 314.1K
 * Testcase Example:  '"abc"'
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int countSubstrings(string &s)
    {
        if (s.size() == 0)
            return 0;

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
            res++;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (j == i + 1)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        if (dp[i + 1][j - 1])
                        {
                            dp[i][j] = 1;
                        }
                    }
                    res += dp[i][j];
                }
            }
        }
        return res;
    }
};
// @lc code=end
