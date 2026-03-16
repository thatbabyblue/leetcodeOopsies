/*
 * Problem: 226. Invert Binary Tree
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/invert-binary-tree/submissions/1949654470/
 * Language: cpp
 * Date: 2026-03-16
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
    void traversal(TreeNode* cur) {
        if (cur == nullptr) return;
        swap(cur->left, cur->right);
        traversal(cur->left);
        traversal(cur->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        traversal(root);
        return root;
    }
};
