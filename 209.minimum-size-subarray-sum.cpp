/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int i = 0, j = 0, sum = 0, ans = INT_MAX;

        int n = nums.size();
        while (i < n && sum < s)
        {
            sum += nums[i];
            i++;
        }

        if (sum < s)
        {
            return 0;
        }

        ans = i;

        while (i < n)
        {
            sum += nums[i];

            while (j <= i && sum >= s)
            {
                ans = min(ans, i - j + 1);
                sum -= nums[j];
                j++;
            }
            i++;
        }
        while (j < i && sum >= s)
        {
            ans = min(ans, i - j);
            sum -= nums[j];
            j++;
        }
        return ans;
    }
};
// @lc code=end
