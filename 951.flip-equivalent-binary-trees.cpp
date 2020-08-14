/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
 *
 * https://leetcode.com/problems/flip-equivalent-binary-trees/description/
 *
 * algorithms
 * Medium (65.59%)
 * Likes:    700
 * Dislikes: 29
 * Total Accepted:    52.3K
 * Total Submissions: 79.6K
 * Testcase Example:  '[1,2,3,4,5,6,null,null,null,7,8]\n[1,3,2,null,6,4,5,null,null,null,null,8,7]'
 *
 * For a binary tree T, we can define a flip operation as follows: choose any
 * node, and swap the left and right child subtrees.
 * 
 * A binary tree X is flip equivalent to a binary tree Y if and only if we can
 * make X equal to Y after some number of flip operations.
 * 
 * Write a function that determines whether two binary trees are flip
 * equivalent.  The trees are given by root nodes root1 and root2.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 =
 * [1,3,2,null,6,4,5,null,null,null,null,8,7]
 * Output: true
 * Explanation: We flipped at nodes with values 1, 3, and 5.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Each tree will have at most 100 nodes.
 * Each value in each tree will be a unique integer in the range [0, 99].
 * 
 * 
 * 
 * 
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) {
            return true;
        }

        if(!root1)
            return false;
        if(!root2)
            return false;

        if(root1->val != root2->val)
            return false;

        if(flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right))
            return true;
        
        return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
    }

};
// @lc code=end

