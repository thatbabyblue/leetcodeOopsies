/*
 * Problem: 404. Sum of Left Leaves
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/sum-of-left-leaves/submissions/1922996414/
 * Language: cpp
 * Date: 2026-02-18
 */

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
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> st;
        if (root == nullptr) return 0;
        st.push(root);
        int sum = 0;
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node->left && !node->left->left && !node->left->right) {
                sum += node->left->val;
            }
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return sum;

    }
};
