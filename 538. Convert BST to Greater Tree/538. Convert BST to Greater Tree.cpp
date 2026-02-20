/*
 * Problem: 538. Convert BST to Greater Tree
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/convert-bst-to-greater-tree/submissions/1924897666/
 * Language: cpp
 * Date: 2026-02-20
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
    int pre = 0;
    void traversal(TreeNode* cur) {
        if (cur == nullptr) return;
        traversal(cur->right);
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        traversal(root);
        return root;
    }
};
