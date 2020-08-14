/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
 *
 * https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
 *
 * algorithms
 * Medium (65.07%)
 * Likes:    586
 * Dislikes: 24
 * Total Accepted:    39.4K
 * Total Submissions: 59.8K
 * Testcase Example:  '[8,3,10,1,6,null,14,null,null,4,7,13]'
 *
 * Given the root of a binary tree, find the maximum value V for which there
 * exists different nodes A and B where V = |A.val - B.val| and A is an
 * ancestor of B.
 * 
 * (A node A is an ancestor of B if either: any child of A is equal to B, or
 * any child of A is an ancestor of B.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [8,3,10,1,6,null,14,null,null,4,7,13]
 * Output: 7
 * Explanation: 
 * We have various ancestor-node differences, some of which are given below :
 * |8 - 3| = 5
 * |3 - 7| = 4
 * |8 - 1| = 7
 * |10 - 13| = 3
 * Among all possible differences, the maximum value of 7 is obtained by |8 -
 * 1| = 7.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the tree is between 2 and 5000.
 * Each node will have value between 0 and 100000.
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

    int ans = INT_MIN;

    int traverse(TreeNode* root) {
        if(!root) {
            return INT_MIN;
        }

        int l = traverse(root->left);
        int r = traverse(root->right);

        if(l == INT_MIN && r == INT_MIN) {
            cout<<root->val<<endl;
            return root->val;
        }
        int diff = INT_MIN;
        int retVal = INT_MAX;
        if(l != INT_MIN) {
            diff = max(diff, abs(root->val - l));
            retVal = min(l, retVal);
        }

        if(r != INT_MIN) {
            diff = max(diff, abs(root->val - r));
            retVal = min(retVal, r);
        }

        ans = max(ans, diff);
        cout<<" L " << l << " R " << r << " D " << diff << " Root " << root->val << " Ret " << retVal <<endl;
        return min(retVal, root->val);
    }

    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;

        traverse(root);
        return ans;
    }
};
// @lc code=end

