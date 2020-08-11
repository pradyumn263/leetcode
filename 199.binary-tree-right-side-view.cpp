/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (53.44%)
 * Likes:    2414
 * Dislikes: 141
 * Total Accepted:    303.5K
 * Total Submissions: 561.2K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int k = q.size();
            int val;
            while(k--) {
                TreeNode* curr = q.front();
                q.pop();
                val = curr->val;

                if(curr->left) {
                    q.push(curr->left);
                }

                if(curr->right) {
                    q.push(curr->right);
                }
            }
            res.push_back(val);
        }
        return res;

    }
};
// @lc code=end

