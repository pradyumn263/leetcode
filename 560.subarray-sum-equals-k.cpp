/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int i = 0, cumSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cumSum += nums[i];
            res += mp[cumSum - k];
            mp[cumSum]++;
        }
        return res;
    }
};
// @lc code=end
