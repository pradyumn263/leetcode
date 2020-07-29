/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        if (n == 0)
            return 0;

        if (n == 1)
            return nums[0];

        vector<int> minProd(n, 0);
        vector<int> maxProd(n, 0);
        int ans = nums[0];
        minProd[0] = nums[0];
        maxProd[0] = nums[0];

        for (i = 1; i < n; i++)
        {
            maxProd[i] = max(maxProd[i - 1] * nums[i], minProd[i - 1] * nums[i]);
            maxProd[i] = max(maxProd[i], nums[i]);

            minProd[i] = min(maxProd[i - 1] * nums[i], minProd[i - 1] * nums[i]);
            minProd[i] = min(minProd[i], nums[i]);

            ans = max(ans, maxProd[i]);
        }
        return ans;
    }
};
// @lc code=end
