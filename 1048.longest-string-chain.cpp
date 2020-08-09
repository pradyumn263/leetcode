/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 *
 * https://leetcode.com/problems/longest-string-chain/description/
 *
 * algorithms
 * Medium (54.22%)
 * Likes:    989
 * Dislikes: 64
 * Total Accepted:    66.3K
 * Total Submissions: 121.3K
 * Testcase Example:  '["a","b","ba","bca","bda","bdca"]'
 *
 * Given a list of words, each word consists of English lowercase letters.
 * 
 * Let's say word1 is a predecessor of word2 if and only if we can add exactly
 * one letter anywhere in word1 to make it equal to word2.  For example, "abc"
 * is a predecessor of "abac".
 * 
 * A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >=
 * 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of
 * word_3, and so on.
 * 
 * Return the longest possible length of a word chain with words chosen from
 * the given list of words.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["a","b","ba","bca","bda","bdca"]
 * Output: 4
 * Explanation: one of the longest word chain is "a","ba","bda","bdca".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 16
 * words[i] only consists of English lowercase letters.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    bool isNext(string &a, string &b) {
        if(a.size() != b.size() - 1) {
            return false;
        }
        bool canSkip = true;
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;
        while(i < n) {
            if(a[i] == b[j]) {
                i++;
                j++;
                continue;
            }

            if(canSkip) {
                j++;
                canSkip = false;
            } else {
                return false;
            }
        }
        return true;
        
    }

    int longestStrChain(vector<string>& words) {
        if(words.size() <= 1) 
            return words.size();

        int n = words.size();
        vector<int> dp(n, 1);
        auto comp = [] (string &a, string &b) {
            return a.size() < b.size();
        };
        sort(words.begin(), words.end(), comp);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(isNext(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        for(int i = 0; i < dp.size(); i++)
            cout<<dp[i]<<" ";
        return *max_element(dp.begin(), dp.end());

    }
};
// @lc code=end

