/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Medium (78.33%)
 * Likes:    1301
 * Dislikes: 39
 * Total Accepted:    133.5K
 * Total Submissions: 170.3K
 * Testcase Example:  '[8,5,1,7,10,12]'
 *
 * Return the root node of a binary search tree that matches the given preorder
 * traversal.
 * 
 * (Recall that a binary search tree is a binary tree where for every node, any
 * descendant of node.left has a value < node.val, and any descendant of
 * node.right has a value > node.val.  Also recall that a preorder traversal
 * displays the value of the node first, then traverses node.left, then
 * traverses node.right.)
 * 
 * It's guaranteed that for the given test cases there is always possible to
 * find a binary search tree with the given requirements.
 * 
 * Example 1:
 * 
 * 
 * Input: [8,5,1,7,10,12]
 * Output: [8,5,10,1,7,null,12]
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= preorder.length <= 100
 * 1 <= preorder[i] <= 10^8
 * The values of preorder are distinct.
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

    TreeNode* helper(vector<int> &preorder, int start, int end) {
        if(end >= preorder.size())
            return nullptr;
        if(end < start)
            return nullptr;

        if(end == start) {
            return new TreeNode(preorder[start]);
        }

        TreeNode* root = new TreeNode(preorder[start]);
        int index = 0;
        for(index = start + 1; index <= end; index++) {
            if(preorder[index] > preorder[start])
                break;
        }

        root->left = helper(preorder, start+1, index-1);
        root->right = helper(preorder, index, end);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size() - 1);
    }
};
// @lc code=end

