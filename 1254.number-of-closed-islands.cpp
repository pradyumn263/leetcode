/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 *
 * https://leetcode.com/problems/number-of-closed-islands/description/
 *
 * algorithms
 * Medium (60.01%)
 * Likes:    412
 * Dislikes: 18
 * Total Accepted:    20.6K
 * Total Submissions: 34K
 * Testcase Example:  '[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]'
 *
 * Given a 2D grid consists of 0s (land) and 1s (water).  An island is a
 * maximal 4-directionally connected group of 0s and a closed island is an
 * island totally (all left, top, right, bottom) surrounded by 1s.
 * 
 * Return the number of closed islands.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: grid =
 * [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 * Output: 2
 * Explanation: 
 * Islands in gray are closed because they are completely surrounded by water
 * (group of 1s).
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,1,1,1,1,1,1],
 * [1,0,0,0,0,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,1,0,1,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,0,0,0,0,1],
 * ⁠              [1,1,1,1,1,1,1]]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= grid.length, grid[0].length <= 100
 * 0 <= grid[i][j] <=1
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>> &g, int i, int j) {
        if(i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j] != 0)
            return;

        g[i][j] = 1;
        dfs(g, i+1, j);
        dfs(g, i-1, j);
        dfs(g, i, j-1);
        dfs(g, i, j+1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        if(n == 0)
            return 0;
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0) {
                dfs(grid, i,0);
            }
            if(grid[i][m-1] == 0) {
                dfs(grid, i, m-1);
            }
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 0) {
                dfs(grid, 0,j);
            }
            if(grid[n-1][j] == 0) 
                dfs(grid,n-1,j);
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(grid[i][j] == 0) {
                    res++;
                    dfs(grid, i,j);
                }
            }
        }

        return res;
    }
};
// @lc code=end

