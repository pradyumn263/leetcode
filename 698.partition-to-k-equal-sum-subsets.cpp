/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 *
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (44.91%)
 * Likes:    1881
 * Dislikes: 116
 * Total Accepted:    88.1K
 * Total Submissions: 196K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * Given an array of integers nums and a positive integer k, find whether it's
 * possible to divide this array into k non-empty subsets whose sums are all
 * equal.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * Output: True
 * Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3),
 * (2,3) with equal sums.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= k <= len(nums) <= 16.
 * 0 < nums[i] < 10000.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> dp;

    bool helper(vector<int> &nums, vector<bool> &visited, int encode, int target, int curr, int k, int start)
    {
        if (curr < 0)
        {
            dp[encode] = false;
            return false;
        }
        if (k == 0)
        {
            dp[encode] = 1;
            return true;
        }

        if (dp[encode] != 2)
            return dp[encode] == 1 ? true : false;

        if (curr == 0)
            return helper(nums, visited, encode, target, target, k - 1, 0);
        bool ans = false;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                int temp = (1 << (15 - i));
                cout << temp << endl;
                ans = helper(nums, visited, encode | temp, target, curr - nums[i], k, i + 1);
                visited[i] = false;
                if (ans)
                {
                    dp[encode] = true;
                    return ans;
                }
            }
        }
        dp[encode] = ans ? true : false;
        return ans;
    }

    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k)
            return false;
        int n = nums.size();
        sum /= k;
        dp.resize(100000, 2);
        vector<bool> visited(n, false);
        return helper(nums, visited, 0, sum, sum, k, 0);
    }
};
// @lc code=end
