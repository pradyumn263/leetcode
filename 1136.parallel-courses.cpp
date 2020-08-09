/*
 * @lc app=leetcode id=1136 lang=cpp
 *
 * [1136] Parallel Courses
 *
 * https://leetcode.com/problems/parallel-courses/description/
 *
 * algorithms
 * Hard (61.01%)
 * Likes:    160
 * Dislikes: 7
 * Total Accepted:    8.4K
 * Total Submissions: 13.7K
 * Testcase Example:  '3\n[[1,3],[2,3]]'
 *
 * There are N courses, labelled from 1 to N.
 * 
 * We are given relations[i] = [X, Y], representing a prerequisite relationship
 * between course X and course Y: course X has to be studied before course Y.
 * 
 * In one semester you can study any number of courses as long as you have
 * studied all the prerequisites for the course you are studying.
 * 
 * Return the minimum number of semesters needed to study all courses.  If
 * there is no way to study all the courses, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: N = 3, relations = [[1,3],[2,3]]
 * Output: 2
 * Explanation: 
 * In the first semester, courses 1 and 2 are studied. In the second semester,
 * course 3 is studied.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: N = 3, relations = [[1,2],[2,3],[3,1]]
 * Output: -1
 * Explanation: 
 * No course can be studied because they depend on each other.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 5000
 * 1 <= relations.length <= 5000
 * relations[i][0] != relations[i][1]
 * There are no repeated relations in the input.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        if(N == 0)
            return 0;
        vector<vector<int>> g(N);
        vector<int> indeg(N, 0);
        for(int i = 0; i < relations.size(); i++) {
            g[relations[i][0]-1].push_back(relations[i][1]-1);
            indeg[relations[i][1]-1]++;
        }
        int sems = 1;
        queue<int> q;
        vector<int> res;
        for(int i = 0; i < indeg.size(); i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int k = q.size();

            while(k--) {
                int curr = q.front();
                q.pop();

                for(int neighbour : g[curr]) {
                    indeg[neighbour]--;
                    if(indeg[neighbour] == 0) {
                        q.push(neighbour);
                    }
                }
                res.push_back(curr);
            }
            
            if(!q.empty())
                sems++;
        }

        if(res.size() != N)
            return -1;

        return sems;
    }
};
// @lc code=end

