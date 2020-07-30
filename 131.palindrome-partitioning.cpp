/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (46.65%)
 * Likes:    1907
 * Dislikes: 67
 * Total Accepted:    231.1K
 * Total Submissions: 488.9K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> res;

    bool isPal(string &s)
    {
        int i = 0;
        int j = s.size() - 1;

        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void helper(string &s, int ind, vector<string> &currset)
    {
        if (ind == s.size())
        {
            res.push_back(currset);
            return;
        }

        string temp;
        for (int i = ind; i < s.size(); i++)
        {
            temp += s[i];
            if (isPal(temp))
            {
                currset.push_back(temp);
                helper(s, i + 1, currset);
                currset.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string &s)
    {
        if (s.size() == 0)
            return {};
        vector<string> currset;
        helper(s, 0, currset);

        return res;
    }
};
// @lc code=end
