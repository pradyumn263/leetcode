/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (37.43%)
 * Likes:    3183
 * Dislikes: 79
 * Total Accepted:    270.6K
 * Total Submissions: 718.4K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */

// @lc code=start
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &mt)
    {
        if (mt.size() == 0)
            return 0;

        int n = mt.size();
        int m = mt[0].size();
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mt[i][j] == '1')
                {
                    matrix[i][j] = 1;
                    res = 1;
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                    continue;
                int currLen = min(matrix[i - 1][j], matrix[i - 1][j - 1]);
                currLen = min(currLen, matrix[i][j - 1]);

                matrix[i][j] = currLen + 1;

                res = max(res, matrix[i][j]);
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        return res * res;
    }
};
// @lc code=end
