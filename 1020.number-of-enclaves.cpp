/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 *
 * https://leetcode.com/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (57.06%)
 * Likes:    314
 * Dislikes: 18
 * Total Accepted:    18.9K
 * Total Submissions: 32.8K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * Given a 2D array A, each cell is 0 (representing sea) or 1 (representing
 * land)
 * 
 * A move consists of walking from one land square 4-directionally to another
 * land square, or off the boundary of the grid.
 * 
 * Return the number of land squares in the grid for which we cannot walk off
 * the boundary of the grid in any number of moves.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * Output: 3
 * Explanation: 
 * There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed
 * because its on the boundary.
 * 
 * Example 2:
 * 
 * 
 * Input: [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * Output: 0
 * Explanation: 
 * All 1s are either on the boundary or can reach the boundary.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 500
 * 1 <= A[i].length <= 500
 * 0 <= A[i][j] <= 1
 * All rows have the same size.
 * 
 */

// @lc code=start
class Solution {
public:

    int dfs(vector<vector<int>> &g, int i, int j) {
        if(i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j] != 1)
            return 0 ;

        g[i][j] = 0;

        return 1 + dfs(g, i+1,j) + dfs(g, i-1, j) + dfs(g, i , j+1) + dfs(g, i , j-1);
    }
   
    int numEnclaves(vector<vector<int>>& A) {
        int res = 0;
        int n = A.size();
        int m = A[0].size();
       
        for(int i = 0; i < n; i++) {
            if(A[i][0] == 1)
                dfs(A, i,0);
            if(A[i][m-1] == 1) {
                dfs(A, i, m-1);
            }
        }
       
        for(int j = 0; j < m; j++) {
            if(A[0][j] == 1) {
                dfs(A, 0, j);
            }
            if(A[n-1][j] == 1) {
                dfs(A, n-1, j);
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(A[i][j] == 1) {
                    res += dfs(A, i,j);
                }
            }
        }
       
        return res;
    }
};
// @lc code=end

