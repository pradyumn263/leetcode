/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (39.11%)
 * Likes:    1638
 * Dislikes: 77
 * Total Accepted:    168.4K
 * Total Submissions: 424.3K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * 
 * Recover the tree without changing its structure.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * Output: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * Output: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 
 * Follow up:
 * 
 * 
 * A solution using O(n) space is pretty straight forward.
 * Could you devise a constant space solution?
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

    TreeNode* first;
    TreeNode* mid;
    TreeNode* last;

    Solution() {
        first = nullptr;
        mid = nullptr;
        last = nullptr;
    }

    void recoverTreeHelper(TreeNode* root, TreeNode* &pred) {
        if(!root)
            return;
        
        recoverTreeHelper(root->left, pred);
        if(pred && root->val < pred->val) {
            if(!mid) {
                first = pred;
                mid = root;
            } else {
                last = root;
            }
        }
        pred = root;
        recoverTreeHelper(root->right, pred);
    }

    void recoverTree(TreeNode* root) {
        if(!root)
            return;
        TreeNode* pred = nullptr;
        recoverTreeHelper(root, pred);

        if(!last) {
            swap(first->val, mid->val);
        } else {
            swap(first->val, last->val);
        }
    }
};
// @lc code=end

