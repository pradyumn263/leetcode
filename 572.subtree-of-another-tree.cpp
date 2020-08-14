/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (44.02%)
 * Likes:    2425
 * Dislikes: 116
 * Total Accepted:    225.1K
 * Total Submissions: 510.2K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * Given two non-empty binary trees s and t, check whether tree t has exactly
 * the same structure and node values with a subtree of s. A subtree of s is a
 * tree consists of a node in s and all of this node's descendants. The tree s
 * could also be considered as a subtree of itself.
 * 
 * Example 1:
 * Given tree s:
 * 
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * 
 * Given tree t:
 * 
 * 
 * ⁠  4 
 * ⁠ / \
 * ⁠1   2
 * 
 * Return true, because t has the same structure and node values with a subtree
 * of s.
 * 
 * 
 * 
 * Example 2:
 * Given tree s:
 * 
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 * 
 * Given tree t:
 * 
 * 
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 * 
 * Return false.
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

    bool isSame(TreeNode* s, TreeNode* t) {
        if(!s && !t) 
            return true;

        if(!s)
            return false;
        if(!t)
            return false;
        
        if(s->val != t->val)
            return false;

        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t)
            return true;
        if(!t)
            return true;
        if(!s)
            return false;

        if(isSame(s->left,t))
            return true;
        if(isSame(s->right, t))
            return true;

        return isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
        
    }
};
// @lc code=end

