/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution
{
public:

    int dfs(vector<vector<int>> &g, int i, int j) {
        if(i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j] == 0)
            return 0;
        
        g[i][j] = 0;
        return 1 + dfs(g, i+1, j) + dfs(g, i-1, j) + dfs(g, i, j+1) + dfs(g, i, j-1);
    }
   
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
       int res = 0;
       int n = grid.size();
       if(n == 0) return 0;
       
       int m = grid[0].size();
       for(int i = 0; i < n; i++) {
           for(int j = 0; j < m; j++) {
               if(grid[i][j] == 1) {
                   res = max(res, dfs(grid, i,j));
               }
           }    
       }

       return res;
    }
};
// @lc code=end
