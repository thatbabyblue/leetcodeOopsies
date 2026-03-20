/*
 * Problem: 110. Balanced Binary Tree
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/balanced-binary-tree/submissions/1954326253/
 * Language: cpp
 * Date: 2026-03-20
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
    int getHeight(TreeNode* node) {
        if (node == nullptr) return 0;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        if (leftHeight == -1) return -1;
        if (rightHeight == -1) return -1;
        return abs(rightHeight - leftHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};
