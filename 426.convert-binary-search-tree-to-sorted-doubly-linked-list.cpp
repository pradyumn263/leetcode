/*
 * @lc app=leetcode id=426 lang=cpp
 *
 * [426] Convert Binary Search Tree to Sorted Doubly Linked List
 *
 * https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/description/
 *
 * algorithms
 * Medium (58.64%)
 * Likes:    937
 * Dislikes: 93
 * Total Accepted:    80K
 * Total Submissions: 135.3K
 * Testcase Example:  '[4,2,5,1,3]'
 *
 * Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in
 * place.
 * 
 * You can think of the left and right pointers as synonymous to the
 * predecessor and successor pointers in a doubly-linked list. For a circular
 * doubly linked list, the predecessor of the first element is the last
 * element, and the successor of the last element is the first element.
 * 
 * We want to do the transformation in place. After the transformation, the
 * left pointer of the tree node should point to its predecessor, and the right
 * pointer should point to its successor. You should return the pointer to the
 * smallest element of the linked list.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [4,2,5,1,3]
 * 
 * 
 * Output: [1,2,3,4,5]
 * 
 * Explanation: The figure below shows the transformed BST. The solid line
 * indicates the successor relationship, while the dashed line means the
 * predecessor relationship.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [2,1,3]
 * Output: [1,2,3]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = []
 * Output: []
 * Explanation: Input is an empty tree. Output is also an empty Linked List.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1]
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -1000 <= Node.val <= 1000
 * Node.left.val < Node.val < Node.right.val
 * All values of Node.val are unique.
 * 0 <= Number of Nodes <= 2000
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* head;
    Node* tail;
    Solution() {
        head = nullptr;
        tail = nullptr;
        
    }
    void helper(Node* root, Node* &parent) {
        if(!root)
            return;

        helper(root->left, parent);
        
        if(parent) {
            root->left = parent;
            parent->right = root;
        } else {
            head = root;
            root->left = nullptr;
        }
        tail = root;
        parent = root;
        helper(root->right, parent);
        
    }

    Node* treeToDoublyList(Node* root) {
        if(!root)
            return root;
        Node* parent = nullptr;
        helper(root, parent);
        if(!head && root)
            return root;
        head->left = tail;
        tail->right = head;
        return head;
    }
};
// @lc code=end

