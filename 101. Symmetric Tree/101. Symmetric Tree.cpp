/*
 * Problem: 101. Symmetric Tree
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/symmetric-tree/submissions/1922702164/
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
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        else if (left == nullptr || right == nullptr) return false;
        else if (left->val != right->val) return false;
        bool outer = compare(left->left, right->right);
        bool inner = compare(left->right, right->left);
        return outer && inner;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return compare(root->left, root->right);
    }
};
