/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution
{
public:
    vector<string> res;
    unordered_map<string, bool> mp;
    void helper(string &s, int ind, vector<bool> &dp, string currset)
    {
        if (ind == s.size())
        {
            currset.pop_back();
            res.push_back(currset);
            return;
        }
        string temp;
        for (int i = ind; i < s.size(); i++)
        {
            temp += s[i];
            if (dp[i + 1] && mp.find(temp) != mp.end())
            {
                helper(s, i + 1, dp, currset + temp + " ");
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();

        if (!n)
            return {};

        for (int i = 0; i < wordDict.size(); i++)
        {
            mp[wordDict[i]] = true;
        }

        vector<bool> dp(n + 1, false);
        dp[n] = true;
        string t;
        t += s[n - 1];
        if (mp.find(t) != mp.end())
            dp[n - 1] = true;

        for (int i = n - 2; i >= 0; i--)
        {
            string temp;
            temp += s[i];
            for (int j = i + 1; j < n; j++)
            {
                if (mp.find(temp) != mp.end() && dp[j])
                {
                    dp[i] = true;
                    break;
                }
                temp += s[j];
            }
            if (mp.find(temp) != mp.end())
            {
                dp[i] = true;
            }
        }
        helper(s, 0, dp, "");
        return res;
    }
};
// @lc code=end
