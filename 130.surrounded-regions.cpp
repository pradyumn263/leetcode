/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (27.64%)
 * Likes:    1910
 * Dislikes: 676
 * Total Accepted:    247K
 * Total Submissions: 879.3K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */

// @lc code=start
class Solution {
public:

    void floodFill(vector<vector<char>> &board, int i, int j, char ch, char to) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] != ch)
            return;

        board[i][j] = to;
        floodFill(board, i+1, j, ch, to);
        floodFill(board, i-1, j, ch, to);
        floodFill(board, i, j+1, ch, to);
        floodFill(board, i, j-1, ch, to);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(); 
        if(n == 0)
            return;
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
               if(board[i][j] == 'O')
                    board[i][j] = '-';
            }
        }
        
        for(int i = 0; i < m; i++) {
            if(board[0][i] == '-') {
                floodFill(board, 0,i, '-', 'O');
            }
            if(board[n-1][i] == '-') {
                floodFill(board, n-1,i, '-', 'O');
            }
        }

        for(int i = 1; i < n; i++) {
            if(board[i][0] == '-') {
                floodFill(board, i, 0, '-', 'O');
            }
            if(board[i][m-1] == '-') {
                floodFill(board, i, m-1, '-', 'O');
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(board[i][j] == '-') {
                    floodFill(board, i,j,'-','X');
                }
            }
        }
    }
};
// @lc code=end

