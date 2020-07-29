/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        if(n == 1)
            return 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 && nums.size() > 1) {
                if(nums[1] < nums[i])
                    return 0;
                continue;
            }
            if(i == n - 1) {
                if(nums[i-1] < nums[i])
                    return i;
                continue;
            }

            if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
                return i;
        }
        return res;
    }
};
// @lc code=end

