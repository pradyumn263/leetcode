/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();

        if (!n)
            return false;

        unordered_map<string, bool> mp;
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
        return dp[0];
    }
};
// @lc code=end
