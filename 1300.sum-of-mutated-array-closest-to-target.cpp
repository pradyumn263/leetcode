/*
 * @lc app=leetcode id=1300 lang=cpp
 *
 * [1300] Sum of Mutated Array Closest to Target
 */

// @lc code=start
class Solution {
public:
    int findSum(vector<int> &nums, int n) {
        int sum = 0;
        for(int x : nums) {
            if(x >= n)
                sum+=n;
            else sum+=x;
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        if(arr.size() == 0)
            return 0;
        
        int sum = accumulate(arr.begin(),arr.end(),0);
        int hi = *max_element(arr.begin(), arr.end());
        int lo = 1;
        if(sum <= target)
            return hi;

        while(lo < hi) {
            int mid = lo + (hi-lo)/2;
            int c = findSum(arr,mid);

            if(c >= target) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }

        int s1 = findSum(arr,lo);
        int s2 = findSum(arr,lo-1);
        if(abs(target-s1) < abs(target-s2))
            return lo;
        else return lo-1;
    }
};
// @lc code=end

