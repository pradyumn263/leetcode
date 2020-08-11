/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 *
 * https://leetcode.com/problems/jump-game-iii/description/
 *
 * algorithms
 * Medium (60.40%)
 * Likes:    484
 * Dislikes: 18
 * Total Accepted:    29.8K
 * Total Submissions: 49.4K
 * Testcase Example:  '[4,2,3,0,3,1,2]\n5'
 *
 * Given an array of non-negative integers arr, you are initially positioned at
 * start index of the array. When you are at index i, you can jump to i +
 * arr[i] or i - arr[i], check if you can reach to any index with value 0.
 * 
 * Notice that you can not jump outside of the array at any time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [4,2,3,0,3,1,2], start = 5
 * Output: true
 * Explanation: 
 * All possible ways to reach at index 3 with value 0 are: 
 * index 5 -> index 4 -> index 1 -> index 3 
 * index 5 -> index 6 -> index 4 -> index 1 -> index 3 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [4,2,3,0,3,1,2], start = 0
 * Output: true 
 * Explanation: 
 * One possible way to reach at index 3 with value 0 is: 
 * index 0 -> index 4 -> index 1 -> index 3
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [3,0,2,1,2], start = 2
 * Output: false
 * Explanation: There is no way to reach at index 1 with value 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 5 * 10^4
 * 0 <= arr[i] < arr.length
 * 0 <= start < arr.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        int n = arr.size();
        vector<bool> visited(n, false);
        q.push(start);

        while(!q.empty()) {
            int k = q.size();

            while(k--) {
                int curr = q.front();
                q.pop();
                if(visited[curr])
                    continue;
                if(arr[curr] == 0) {
                    return true;
                }
                visited[curr] = true;
                
                if(curr - arr[curr] >= 0) 
                    q.push(curr-arr[curr]);

                if(curr + arr[curr] < n)
                    q.push(curr+arr[curr]);

            }
        }
        
        return false;
    }
};
// @lc code=end

