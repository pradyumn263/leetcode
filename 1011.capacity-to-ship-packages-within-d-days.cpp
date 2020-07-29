/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
public:

    bool canShip(vector<int> &nums, int capacity, int day) {
        int usedDays = 0;
        int currentWeight = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > capacity)
                return false;
            currentWeight += nums[i];
            if(currentWeight > capacity) {
                usedDays++;
                currentWeight = 0;
                currentWeight += nums[i];
            }
        }
        if(currentWeight)
            usedDays++;
        return usedDays <= day;
    }


    int shipWithinDays(vector<int>& weights, int D) {
        if(weights.size() == 0)
            return 0;
        if(weights.size() == 1)
            return weights[0];


        int lo = *min_element(weights.begin(),weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);

        while(lo < hi) {
            int mid = lo + (hi - lo)/2;
            if(canShip(weights,mid,D)) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        } 

        if(canShip(weights, lo, D))
            return lo;

        return accumulate(weights.begin(), weights.end(),0);   
    }
};
// @lc code=end

