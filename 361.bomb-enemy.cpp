/*
 * @lc app=leetcode id=361 lang=cpp
 *
 * [361] Bomb Enemy
 *
 * https://leetcode.com/problems/bomb-enemy/description/
 *
 * algorithms
 * Medium (45.80%)
 * Likes:    467
 * Dislikes: 71
 * Total Accepted:    45.6K
 * Total Submissions: 99K
 * Testcase Example:  '[["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]'
 *
 * Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0'
 * (the number zero), return the maximum enemies you can kill using one bomb.
 * The bomb kills all the enemies in the same row and column from the planted
 * point until it hits the wall since the wall is too strong to be destroyed.
 * Note: You can only put the bomb at an empty cell.
 * 
 * Example:
 * 
 * 
 * 
 * Input: [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
 * Output: 3 
 * Explanation: For the given grid,
 * 
 * 0 E 0 0 
 * E 0 W E 
 * 0 E 0 0
 * 
 * Placing a bomb at (1,1) kills 3 enemies.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dp;

    int dfs(vector<vector<char>> &g, vector<vector<bool>> &visited, int i, int j) {
        if(i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || visited[i][j] ) {
            return 0;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        visited[i][j] = true;
        int res = g[i][j] == 'E' ? 1 : 0;
        return res + dfs(g, visited, i+1, j) + dfs(g, visited, i-1,j) + dfs(g, visited, i, j+1) + dfs(g, visited, i , j-1);
    }

    int maxKilledEnemies(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n, vector<int> (m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'W' || grid[i][j] == '0')
                    dp[i][j] = 0;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vector<vector<bool>> visited(n, vector<bool> (m, false));
                if(grid[i][j] == '0') {
                    dp[i][j] = dfs(grid, visited, i,j);
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        for(int i = 0; i < dp.size(); i++) {
            for(int j = 0; j < dp[i].size(); j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }

};
// @lc code=end

