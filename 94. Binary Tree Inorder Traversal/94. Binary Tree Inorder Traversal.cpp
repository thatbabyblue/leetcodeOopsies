/*
 * Problem: 94. Binary Tree Inorder Traversal
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/1921658549/
 * Language: cpp
 * Date: 2026-02-17
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
    void traversal(TreeNode* cur, vector<int>& res) {
        if (cur == nullptr) return;
        traversal(cur->left, res);
        res.push_back(cur->val);
        traversal(cur->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};
