/*
 * Problem: 111. Minimum Depth of Binary Tree
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/1922866198/
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        if (root->left && !root->right) return 1 + leftDepth;
        if (!root->left && root->right) return 1 + rightDepth;
        return 1 + min(leftDepth, rightDepth);
    }
};
