/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (46.53%)
 * Likes:    2685
 * Dislikes: 110
 * Total Accepted:    170K
 * Total Submissions: 366.3K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.
 * 
 * Example 1:
 * 
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The length of the given array is positive and will not exceed 20.
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        if (S > 1000 || S < -1000)
            return 0;
        vector<vector<int>> dp(n, vector<int>(2005, 0));

        dp[n - 1][nums[n - 1] + 1000] = 1;
        dp[n - 1][((-1) * nums[n - 1]) + 1000] += 1;

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = -1000; j <= 1000; j++)
            {
                if ((j - nums[i]) + 1000 >= 0)
                {
                    dp[i][j + 1000] = dp[i + 1][(j - nums[i]) + 1000];
                }

                if ((j + nums[i]) + 1000 < dp[i].size())
                    dp[i][j + 1000] += dp[i + 1][(j + nums[i]) + 1000];
            }
        }

        return dp[0][S + 1000];
    }
};
// @lc code=end
