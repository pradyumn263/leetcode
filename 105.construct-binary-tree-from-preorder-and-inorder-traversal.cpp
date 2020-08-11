/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (47.91%)
 * Likes:    3600
 * Dislikes: 98
 * Total Accepted:    374.4K
 * Total Submissions: 767K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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

    TreeNode* helper(int preStart, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder) {
        if(preStart >= preorder.size() || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inIndex = 0;
        for(int i = inStart; i <= inEnd; i++) {
            if(inorder[i] == root->val)
                inIndex = i;
        }

        root->left = helper(preStart+1, inStart, inIndex-1, preorder, inorder);
        root->right = helper(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder);

        return root;
    }
  
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0,0,inorder.size() - 1, preorder, inorder);
    }
};
// @lc code=end

