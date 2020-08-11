/*
 * @lc app=leetcode id=366 lang=cpp
 *
 * [366] Find Leaves of Binary Tree
 *
 * https://leetcode.com/problems/find-leaves-of-binary-tree/description/
 *
 * algorithms
 * Medium (70.20%)
 * Likes:    1063
 * Dislikes: 17
 * Total Accepted:    72.7K
 * Total Submissions: 103.1K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given a binary tree, collect a tree's nodes as if you were doing this:
 * Collect and remove all leaves, repeat until the tree is empty.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,4,5]
 * 
 * 1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * Output: [[4,5,3],[2],[1]]
 * 
 * 
 * 
 * 
 * Explanation:
 * 
 * 1. Removing the leaves [4,5,3] would result in this tree:
 * 
 * 
 * ⁠         1
 * ⁠        / 
 * ⁠       2          
 * 
 * 
 * 
 * 
 * 2. Now removing the leaf [2] would result in this tree:
 * 
 * 
 * ⁠         1          
 * 
 * 
 * 
 * 
 * 3. Now removing the leaf [1] would result in the empty tree:
 * 
 * 
 * ⁠         []         
 * 
 * [[3,5,4],[2],[1]], [[3,4,5],[2],[1]], etc, are also consider correct answers
 * since per each level it doesn't matter the order on which elements are
 * returned.
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

    int findLeavesHelper(TreeNode* root) {
        if(!root)
            return 0;

        int l = findLeavesHelper(root->left);
        int r = findLeavesHelper(root->right);

        int index = max(l, r);
        if(res.size() <= index)
            res.push_back({});
        
        res[index].push_back(root->val);
        return index+1;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        if(!root)
            return {};

        findLeavesHelper(root);
        return res;
    }
};
// @lc code=end

