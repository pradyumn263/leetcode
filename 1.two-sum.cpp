/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(target - nums[i]) == mp.end()) {
                mp[nums[i]] = i;
            } else {
                vector<int> res;
                res.push_back(mp[target - nums[i]]);
                res.push_back(i);

                return res;
            }
        }
        return {};
    }
};
// @lc code=end

