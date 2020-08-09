/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (30.35%)
 * Likes:    2683
 * Dislikes: 140
 * Total Accepted:    266.4K
 * Total Submissions: 872K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 * 
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int n = nums.size();
        int currEnd = 0, currFarthest = 0, i = 0, jumps = 0;
        for(i = 0; i < n-1; i++) {
            currFarthest = max(currFarthest, i + nums[i]);

            if(i == currEnd) {
                jumps++;
                currEnd = currFarthest;
            }
        }

        return jumps;
    }
};
// @lc code=end

