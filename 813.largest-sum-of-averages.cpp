/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 *
 * https://leetcode.com/problems/largest-sum-of-averages/description/
 *
 * algorithms
 * Medium (49.49%)
 * Likes:    921
 * Dislikes: 44
 * Total Accepted:    24.5K
 * Total Submissions: 49K
 * Testcase Example:  '[9,1,2,3,9]\n3'
 *
 * We partition a row of numbers A into at most K adjacent (non-empty) groups,
 * then our score is the sum of the average of each group. What is the largest
 * score we can achieve?
 * 
 * Note that our partition must use every number in A, and that scores are not
 * necessarily integers.
 * 
 * 
 * Example:
 * Input: 
 * A = [9,1,2,3,9]
 * K = 3
 * Output: 20
 * Explanation: 
 * The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9
 * + (1 + 2 + 3) / 3 + 9 = 20.
 * We could have also partitioned A into [9, 1], [2], [3, 9], for example.
 * That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= A.length <= 100.
 * 1 <= A[i] <= 10000.
 * 1 <= K <= A.length.
 * Answers within 10^-6 of the correct answer will be accepted as correct.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        if(A.size() == 0 || K == 0) 
            return 0;

        int n = A.size();
        vector<vector<double>> dp(n, vector<double>(K+1, 0));
        vector<double> cumsum (n + 1);
        for(int i = 1; i <= n; i++) {
            cumsum[i] = cumsum[i-1]+A[i-1];
            dp[i-1][1] = cumsum[i]/i;
        }

        for(int j = 2; j <= K; j++) {
            for(int i = 0; i < n; i++) {
                double currMax = -DBL_MAX;
                for(int p = 0; p < i; p++) {
                    double sum = dp[p][j-1] + (cumsum[i+1] - cumsum[p+1])/(i-p);
                    currMax = max(sum, currMax);
                }
                dp[i][j] = currMax;
            }
        }

        return dp[n-1][K];
    }
};
// @lc code=end

