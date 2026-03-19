/*
 * Problem: 111. Minimum Depth of Binary Tree
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/1952747977/
 * Language: cpp
 * Date: 2026-03-19
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
    int getDepth(TreeNode* node) {
        if (node == nullptr) return 0;
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        if (node->left == nullptr && node->right != nullptr) return 1 + rightDepth;
        if (node->right == nullptr && node->left != nullptr) return 1 + leftDepth;
        int res = 1 + min(leftDepth, rightDepth);
        return res;
    }
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};
