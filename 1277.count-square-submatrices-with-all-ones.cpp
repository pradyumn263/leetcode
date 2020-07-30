/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 *
 * https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/
 *
 * algorithms
 * Medium (72.90%)
 * Likes:    1042
 * Dislikes: 18
 * Total Accepted:    64.9K
 * Total Submissions: 88.9K
 * Testcase Example:  '[[0,1,1,1],[1,1,1,1],[0,1,1,1]]'
 *
 * Given a m * n matrix of ones and zeros, return how many square submatrices
 * have all ones.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix =
 * [
 * [0,1,1,1],
 * [1,1,1,1],
 * [0,1,1,1]
 * ]
 * Output: 15
 * Explanation: 
 * There are 10 squares of side 1.
 * There are 4 squares of side 2.
 * There is  1 square of side 3.
 * Total number of squares = 10 + 4 + 1 = 15.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = 
 * [
 * ⁠ [1,0,1],
 * ⁠ [1,1,0],
 * ⁠ [1,1,0]
 * ]
 * Output: 7
 * Explanation: 
 * There are 6 squares of side 1.  
 * There is 1 square of side 2. 
 * Total number of squares = 6 + 1 = 7.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 300
 * 1 <= arr[0].length <= 300
 * 0 <= arr[i][j] <= 1
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                    continue;
                int curLen;
                if (i == 0 || j == 0)
                {
                    curLen = 0;
                }
                else
                {
                    curLen = min(matrix[i - 1][j], matrix[i - 1][j - 1]);
                    curLen = min(curLen, matrix[i][j - 1]);
                }
                if (curLen)
                    matrix[i][j] = curLen + 1;
                res += matrix[i][j];
            }
        }
        return res;
    }
};
// @lc code=end
