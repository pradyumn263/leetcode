/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (45.96%)
 * Likes:    1916
 * Dislikes: 69
 * Total Accepted:    340.8K
 * Total Submissions: 728.7K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<vector<int>> res;

    void traverse(TreeNode* root, vector<int> &currset, int sum) {
        if(!root)
            return;

        if(!root->left && !root->right) {
            sum-=root->val;
            currset.push_back(root->val);
            if(sum == 0) {
                res.push_back(currset);
            }
            currset.pop_back();
            return;
        }
        currset.push_back(root->val);
        sum-=root->val;
        traverse(root->left, currset, sum);
        traverse(root->right, currset, sum);
        currset.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> currset;
        traverse(root, currset,sum);
        return res;
    }
};
// @lc code=end

