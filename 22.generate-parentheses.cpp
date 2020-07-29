/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    void helper(vector<string> &res, string &currset, int n, int l ,int r) {
        if(l == n && r == n) {
            res.push_back(currset);
            return;
        }

        if(l < n) {
            currset.push_back('(');
            helper(res,currset,n,l+1,r);
            currset.pop_back();
        }

        if(r < l) {
            currset.push_back(')');
            helper(res,currset,n,l,r+1);
            currset.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string currset;
        helper(res,currset,n,0,0);
        return res;
    }
};
// @lc code=end

