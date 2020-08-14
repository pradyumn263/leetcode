/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (59.54%)
 * Likes:    2732
 * Dislikes: 65
 * Total Accepted:    416.3K
 * Total Submissions: 691K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,1,4,null,2], k = 1
 * ⁠  3
 * ⁠ / \
 * ⁠1   4
 * ⁠ \
 * 2
 * Output: 1
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * ⁠      5
 * ⁠     / \
 * ⁠    3   6
 * ⁠   / \
 * ⁠  2   4
 * ⁠ /
 * ⁠1
 * Output: 3
 * 
 * 
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to
 * find the kth smallest frequently? How would you optimize the kthSmallest
 * routine?
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of elements of the BST is between 1 to 10^4.
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
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

    stack<TreeNode*> st;

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        int ans = st.top()->val;

        TreeNode* temp = st.top();
        st.pop();

        temp = temp->right;
        while(temp) {
            st.push(temp);
            temp = temp->left;
        }
        return ans;
    }

    void createIterator(TreeNode* root) {
        while(root) {
            st.push(root);
            root=root->left;
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        createIterator(root);
        int res;
        while(k-- && hasNext()) {
            res = next();
        }

        return res;
    }
};
// @lc code=end

