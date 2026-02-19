/*
 * Problem: 530. Minimum Absolute Difference in BST
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/submissions/1924030186/
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
    int res = INT_MAX;
    TreeNode* pre = nullptr;
    void traversal(TreeNode* cur) {
        if (cur == nullptr) return;
        traversal(cur->left);
        if (pre != nullptr) {
            res = min(res, cur->val - pre->val);
        }
        pre = cur;
        traversal(cur->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return res;
    }
};
