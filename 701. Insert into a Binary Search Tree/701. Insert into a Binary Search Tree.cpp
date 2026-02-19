/*
 * Problem: 701. Insert into a Binary Search Tree
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/submissions/1924742629/
 * Language: cpp
 * Date: 2026-02-19
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        if (val > root->val) root->right = insertIntoBST(root->right, val);
        if (val < root->val) root->left = insertIntoBST(root->left, val);
        return root;
    }
};
