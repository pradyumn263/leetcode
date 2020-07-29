/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 *
 * https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (49.03%)
 * Likes:    1195
 * Dislikes: 46
 * Total Accepted:    60.5K
 * Total Submissions: 123.4K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * Given two integer arrays A and B, return the maximum length of an subarray
 * that appears in both arrays.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * Output: 3
 * Explanation: 
 * The repeated subarray with maximum length is [3, 2, 1].
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(!A.size() || !B.size())
            return 0;

        vector<vector<int>> dp(A.size(), vector<int>(B.size(),0));
        int res = 0;
        for(int j = 0; j < dp[0].size(); j++) {
            if(A[0] == B[j]) {
                dp[0][j] = 1;
            }
            res = max(res,dp[0][j]);
        }

        for(int i = 0; i < dp.size(); i++) {
            if(B[0] == A[i]) {
                dp[i][0] = 1;
            }
            res = max(res,dp[i][0]);
        }

        for(int i = 1; i < dp.size(); i++) {
            for(int j = 1; j < dp[i].size(); j++) {
                if(A[i] == B[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                res = max(res,dp[i][j]);
            }
        }
        return res;


    }
};
// @lc code=end

