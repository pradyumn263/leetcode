/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (39.69%)
 * Likes:    1953
 * Dislikes: 122
 * Total Accepted:    178.7K
 * Total Submissions: 426K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 * 
 * Example:
 * 
 * 
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * Note:  
 * 
 * 
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 * 
 */

// @lc code=start
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n == 1)
            return 1;

        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        unordered_map<long long int, bool> mp;

        int i = 1;
        pq.push(1);
        while (i < n)
        {
            i++;
            long long int temp = pq.top();
            pq.pop();
            if (mp.find(temp * 2) == mp.end())
            {

                pq.push(temp * 2);
                mp[temp * 2] = true;
            }
            if (mp.find(temp * 3) == mp.end())
            {
                pq.push(temp * 3);
                mp[temp * 3] = true;
            }
            if (mp.find(temp * 5) == mp.end())
            {
                pq.push(temp * 5);
                mp[temp * 5] = true;
            }
        }

        return pq.top();
    }
};
// @lc code=end
