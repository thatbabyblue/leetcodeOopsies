/*
 * Problem: 450. Delete Node in a BST
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/delete-node-in-a-bst/submissions/1924818277/
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val == key) {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (root->left && !root->right) {
                auto node = root->left;
                delete root;
                return node;
            } else if (root->right && !root->left) {
                auto node = root->right;
                delete root;
                return node;
            } else {
                TreeNode* cur = root->right;
                while (cur->left) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
        }
        if (root->val < key) root->right = deleteNode(root->right, key);
        if (root->val > key) root->left = deleteNode(root->left, key);
        return root;
    }
};
