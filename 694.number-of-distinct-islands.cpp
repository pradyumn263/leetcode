/*
 * @lc app=leetcode id=694 lang=cpp
 *
 * [694] Number of Distinct Islands
 *
 * https://leetcode.com/problems/number-of-distinct-islands/description/
 *
 * algorithms
 * Medium (55.47%)
 * Likes:    840
 * Dislikes: 51
 * Total Accepted:    61.1K
 * Total Submissions: 109.2K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.)  You
 * may assume all four edges of the grid are surrounded by water.
 * 
 * Count the number of distinct islands.  An island is considered to be the
 * same as another if and only if one island can be translated (and not rotated
 * or reflected) to equal the other.
 * 
 * Example 1:
 * 
 * 11000
 * 11000
 * 00011
 * 00011
 * 
 * Given the above grid map, return 1.
 * 
 * 
 * Example 2:
 * 11011
 * 10000
 * 00001
 * 11011
 * Given the above grid map, return 3.
 * Notice that:
 * 
 * 11
 * 1
 * 
 * and
 * 
 * ⁠1
 * 11
 * 
 * are considered different island shapes, because we do not consider
 * reflection / rotation.
 * 
 * 
 * Note:
 * The length of each dimension in the given grid does not exceed 50.
 * 
 */

// @lc code=start
class Solution {
public:

    void dfs(vector<vector<int>> &g, string &s, int x, int y, char ch) {
        if(x < 0 || y < 0 || x >= g.size() || y >= g[x].size() || g[x][y] != 1)
            return ;
        g[x][y] = 0;
        s += ch;
        
        dfs(g, s, x-1, y, 'u');
        dfs(g, s, x+1, y, 'd');
        dfs(g, s, x, y-1, 'l');
        dfs(g, s, x, y+1, 'r');
        s+='b';
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> st;
      
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    string s;
                    dfs(grid, s, i,j,'o');
                    st.insert(s);
                }
            }
        }
        return st.size();
    }
};
// @lc code=end

