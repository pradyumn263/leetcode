/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (43.32%)
 * Likes:    2724
 * Dislikes: 71
 * Total Accepted:    184.8K
 * Total Submissions: 424.2K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 * 
 * Note:
 * 
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2)
            return false;
        if (n == 1)
            return false;

        sum /= 2;
        vector<vector<bool>> dp(2, vector<bool>(sum + 1, false));

        for (int i = 0; i < dp[(n - 1) % 2].size(); i++)
        {
            if (nums[(n - 1)] == i)
                dp[(n - 1) % 2][i] = true;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < dp[i % 2].size(); j++)
            {
                dp[i % 2][j] = dp[(i + 1) % 2][j];
                if (!dp[i % 2][j])
                {
                    if (j - nums[i] >= 0)
                        dp[i % 2][j] = dp[(i + 1) % 2][j - nums[i]];
                }
            }
        }
        return dp[0][sum];
    }
};
// @lc code=end
