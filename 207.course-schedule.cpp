/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (42.64%)
 * Likes:    4003
 * Dislikes: 181
 * Total Accepted:    431.9K
 * Total Submissions: 1M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 1 <= numCourses <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    set<int> whiteSet;
    set<int> graySet;
    set<int> blackSet;

    bool isCycle(vector<vector<int>> &g, int curr)
    {
        whiteSet.erase(curr);
        graySet.insert(curr);

        for (int i = 0; i < g[curr].size(); i++)
        {
            if (blackSet.find(g[curr][i]) != blackSet.end())
                continue;

            if (graySet.find(g[curr][i]) != graySet.end())
                return true;

            if (isCycle(g, g[curr][i]))
                return true;
        }

        graySet.erase(curr);
        blackSet.insert(curr);
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &nums)
    {

        vector<vector<int>> g(numCourses);

        for (int i = 0; i < nums.size(); i++)
        {
            g[nums[i][1]].push_back(nums[i][0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            whiteSet.insert(i);
        }

        while (whiteSet.size())
        {
            if (isCycle(g, *whiteSet.begin()))
                return false;
        }
        return true;
    }
};
// @lc code=end
