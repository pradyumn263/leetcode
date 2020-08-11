/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (46.50%)
 * Likes:    4361
 * Dislikes: 107
 * Total Accepted:    677.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Follow up: Solve it both recursively and iteratively.
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

    bool isSymmmetricHelper(TreeNode* rootl, TreeNode* rootr) {
        if(!rootl && !rootr)
            return true;

        if(!rootl)
            return false;

        if(!rootr)
            return false;

        if(rootl->val != rootr->val)
            return false;

        return isSymmmetricHelper(rootl->left, rootr->right) && isSymmmetricHelper(rootl->right, rootr->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;

        return isSymmmetricHelper(root->left, root->right);
        
    }
};
// @lc code=end

