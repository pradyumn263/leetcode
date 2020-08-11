/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (57.20%)
 * Likes:    2600
 * Dislikes: 220
 * Total Accepted:    420.8K
 * Total Submissions: 726.2K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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

    TreeNode* createTree(vector<int> &nums, int lo, int hi) {
        if(hi < lo) 
            return nullptr;
        if(hi == lo)
            return new TreeNode(nums[lo]);
    
        int mid = lo + (hi - lo + 1)/2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createTree(nums, lo, mid-1);
        root->right = createTree(nums, mid+1, hi);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;

        if(nums.size() == 0)
            return new TreeNode(nums[0]);

        return createTree(nums, 0, nums.size() - 1);
        
    }
};
// @lc code=end

