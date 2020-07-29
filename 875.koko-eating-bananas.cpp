/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 *
 * https://leetcode.com/problems/koko-eating-bananas/description/
 *
 * algorithms
 * Medium (51.58%)
 * Likes:    747
 * Dislikes: 68
 * Total Accepted:    39.3K
 * Total Submissions: 76.2K
 * Testcase Example:  '[3,6,7,11]\r\n8\r'
 *
 * Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has
 * piles[i] bananas.  The guards have gone and will come back in H hours.
 * 
 * Koko can decide her bananas-per-hour eating speed of K.  Each hour, she
 * chooses some pile of bananas, and eats K bananas from that pile.  If the
 * pile has less than K bananas, she eats all of them instead, and won't eat
 * any more bananas during this hour.
 * 
 * Koko likes to eat slowly, but still wants to finish eating all the bananas
 * before the guards come back.
 * 
 * Return the minimum integer K such that she can eat all the bananas within H
 * hours.
 * 
 * 
 * Example 1:
 * Input: piles = [3,6,7,11], H = 8
 * Output: 4
 * Example 2:
 * Input: piles = [30,11,23,4,20], H = 5
 * Output: 30
 * Example 3:
 * Input: piles = [30,11,23,4,20], H = 6
 * Output: 23
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= piles.length <= 10^4
 * piles.length <= H <= 10^9
 * 1 <= piles[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    bool canEat(vector<int> &nums, int speed, int H) {
        int currTime = 0;
        int i = 0;
        while(i < nums.size()) {
            int temp = nums[i];
            if(temp%speed) {
                currTime++;
                temp-= temp%speed;
            }
            if(temp) {
                currTime += temp/speed;
            }
            i++;
        }
        return currTime <= H;
    }


    int minEatingSpeed(vector<int>& piles, int H) {
        if(piles.size() == 0)
            return 0;
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;

            if(canEat(piles,mid,H)) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }

        return lo;
        
    }
};
// @lc code=end

