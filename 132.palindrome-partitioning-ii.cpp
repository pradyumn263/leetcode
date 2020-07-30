/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (29.96%)
 * Likes:    1149
 * Dislikes: 34
 * Total Accepted:    132.7K
 * Total Submissions: 440.2K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using
 * 1 cut.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<bool>> pal;

    void populatePal(string &s)
    {
        for (int i = 0; i < pal.size(); i++)
        {
            pal[i][i] = true;
        }

        for (int i = pal.size() - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < pal[i].size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j == i + 1)
                    {
                        pal[i][j] = true;
                    }
                    else
                    {

                        pal[i][j] = pal[i + 1][j - 1];
                    }
                }
            }
        }
    }

    int minCut(string &s)
    {
        int n = s.size();
        if (n == 0)
            return 0;

        if (n == 1)
            return 0;

        vector<int> dp(n + 1, INT_MAX);
        pal.resize(n, vector<bool>(n, false));
        populatePal(s);

        dp[n] = 0;
        for (int i = n - 1; i >= 0; i -= 1)
        {
            string temp;

            for (int j = i; j < n; j++)
            {
                temp += s[j];
                if (pal[i][j])
                {
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
            }
            if (pal[i][n - 1])
                dp[i] = min(dp[i], 0);
        }
        return dp[0];
    }
};
// @lc code=end
