/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = 0;
        if(matrix.size() == 0)
            return false;

        j = matrix[0].size()-1;

        while(i < matrix.size() && j >= 0) {
            if(matrix[i][j] == target) {
                return true;
            }
            if(matrix[i][j] > target) {
                j--;
                continue;
            } 

            if(matrix[i][j] < target) {
                i++;
                continue;
            }
        }
        return false;
    }
};
// @lc code=end

