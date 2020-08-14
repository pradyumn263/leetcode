/*
 * @lc app=leetcode id=333 lang=cpp
 *
 * [333] Largest BST Subtree
 *
 * https://leetcode.com/problems/largest-bst-subtree/description/
 *
 * algorithms
 * Medium (35.46%)
 * Likes:    625
 * Dislikes: 60
 * Total Accepted:    47K
 * Total Submissions: 131K
 * Testcase Example:  '[10,5,15,1,8,null,7]'
 *
 * Given a binary tree, find the largest subtree which is a Binary Search Tree
 * (BST), where largest means subtree with largest number of nodes in it.
 * 
 * Note:
 * A subtree must include all of its descendants.
 * 
 * Example:
 * 
 * 
 * Input: [10,5,15,1,8,null,7]
 * 
 * ⁠  10 
 * ⁠  / \ 
 * ⁠ 5  15 
 * ⁠/ \   \ 
 * 1   8   7
 * 
 * Output: 3
 * Explanation: The Largest BST Subtree in this case is the highlighted one.
 * ⁠            The return value is the subtree's size, which is 3.
 * 
 * 
 * Follow up:
 * Can you figure out ways to solve it with O(n) time complexity?
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
    TreeNode* ans = nullptr;
    int maxSize = 0;

    bool isBST(TreeNode* root, int minVal, int maxVal) {
        if(!root)
            return true;

        if(root->val < minVal || root->val > maxVal) 
            return false;

        return isBST(root->left, minVal, root->val-1) && isBST(root->right, root->val+1, maxVal);    
    }

    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }


    void helper(TreeNode* root) {
        if(!root)
            return;
        
        if(isBST(root, INT_MIN, INT_MAX)) {
            int size = countNodes(root);
            if(size > maxSize) {
                ans = root;
                maxSize = size;
            }
            return;
        } 

        helper(root->left);
        helper(root->right);
    }

    int largestBSTSubtree(TreeNode* root) {
        if(!root)
            return 0;

        helper(root);
        return maxSize;
    }
};
// @lc code=end

