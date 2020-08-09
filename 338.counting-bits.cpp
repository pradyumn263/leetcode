/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (69.18%)
 * Likes:    2810
 * Dislikes: 172
 * Total Accepted:    294.1K
 * Total Submissions: 423.1K
 * Testcase Example:  '2'
 *
 * Given a non negative integer number num. For every numbers i in the range 0
 * ≤ i ≤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: [0,1,1]
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: [0,1,1,2,1,2]
 * 
 * 
 * Follow up:
 * 
 * 
 * It is very easy to come up with a solution with run time
 * O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
 * single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount in c++ or in any other language.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0) {
            return {0};
        }
        if(num == 1) {
            return {0,1};
        }
        if(num == 2) {
            return {0,1,1};
        }

        if(num == 3) {
            return {0,1,1,2};
        }

        vector<int> res(num+1, 0);

        res[1] = 1;
        res[2] = 1;
        res[3] = 2;

        int i = 4; 
        int j = 0;

        int stopPos = i;

        while(i < res.size()) {
            if(j == stopPos) {
                j = 0;
                stopPos = i;
            }
            cout<<res[j] <<" " << res[i]<<endl;
            res[i] = 1 + res[j];
            i++;
            j++;
        }

        return res;
    }
};
// @lc code=end

