/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:

    void helper(vector<string> &res, vector<string> &mp, string &currset, int i, string &inp) {
        if(i == inp.size()) {
            res.push_back(currset);
            return;
        }
        int n = inp[i] - '0';
        for(int j = 0; j < mp[n].size(); j++) {
            currset.push_back(mp[n][j]);
            helper(res,mp,currset,i+1,inp);
            currset.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string &digits) {
        if(digits.size() == 0)
            return {};
        vector<string> res(10);
        res[2] = "abc";
        res[3] = "def";
        res[4] = "ghi";
        res[5] = "jkl";
        res[6] = "mno";
        res[7] = "pqrs";
        res[8] = "tuv";
        res[9] = "wxyz";
        vector<string> op;
        string currset;
        helper(op,res,currset,0,digits);
        return op;

    }
};
// @lc code=end

