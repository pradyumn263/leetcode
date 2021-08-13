/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (38.94%)
 * Likes:    4435
 * Dislikes: 302
 * Total Accepted:    617.9K
 * Total Submissions: 1.6M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
            return intervals;

        auto comp = [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0])
                return a[1] < b[1];

            return a[0] < b[0];
        };

        sort(intervals.begin(), intervals.end(), comp);

        vector<vector<int>> res;

        int i = 0;
        while (i < intervals.size())
        {
            vector<int> currset;
            currset.push_back(intervals[i][0]);
            int j = i + 1;
            int currEnd = intervals[i][1];
            while (j < intervals.size() && intervals[j][0] <= currEnd)
            {
                currEnd = max(currEnd, intervals[j][1]);
                j++;
            }
            j--;
            currset.push_back(max(intervals[i][1], currEnd));
            res.push_back(currset);
            i = j + 1;
        }
        return res;
    }
};
// @lc code=end
//changes made by RJs
