/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        if (nums.size() == 1)
            return nums[0];

        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        int n = nums.size();

        vector<int> dp(n, 0);
        dp[n - 1] = nums[n - 1];
        dp[n - 2] = max(nums[n - 1], nums[n - 2]);

        for (int i = n - 3; i >= 0; i--)
        {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }
        return dp[0];
    }
};
// @lc code=end
