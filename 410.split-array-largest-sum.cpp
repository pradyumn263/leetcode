/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 *
 * https://leetcode.com/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (44.29%)
 * Likes:    1718
 * Dislikes: 80
 * Total Accepted:    88.8K
 * Total Submissions: 200.4K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * Given an array which consists of non-negative integers and an integer m, you
 * can split the array into m non-empty continuous subarrays. Write an
 * algorithm to minimize the largest sum among these m subarrays.
 * 
 * 
 * Note:
 * If n is the length of array, assume the following constraints are
 * satisfied:
 * 
 * 1 ≤ n ≤ 1000
 * 1 ≤ m ≤ min(50, n)
 * 
 * 
 * 
 * Examples: 
 * 
 * Input:
 * nums = [7,2,5,10,8]
 * m = 2
 * 
 * Output:
 * 18
 * 
 * Explanation:
 * There are four ways to split nums into two subarrays.
 * The best way is to split it into [7,2,5] and [10,8],
 * where the largest sum among the two subarrays is only 18.
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    bool isValid(vector<long long int> &nums, long long int maxPossibleSum, long long int m) {
        long long int totPart = 0;
        long long int currSum = 0;
        long long int i = 0;
        while(i < nums.size()) {
            currSum += (long long int)nums[i];
            if(currSum > maxPossibleSum) {
                currSum = (long long int)nums[i];
                totPart++;
            } 
            i++;
        }
        if(currSum > maxPossibleSum)
            totPart+=2;
        else if(currSum)
            totPart++;

        return totPart <= m;
        
    }

    int splitArray(vector<int>& num, int m) {
        if(num.size() == 0)
            return 0;
        vector<long long int> nums;
        for(int x : num) {
            nums.push_back(x);
        }
        long long int lo = *max_element(nums.begin(), nums.end());
        long long int hi = accumulate(nums.begin(),nums.end(), 0);

        while(lo < hi) {
            long long int mid = lo + (hi - lo)/2;

            if(isValid(nums,mid,m)) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }

        return lo;
    }
};
// @lc code=end

