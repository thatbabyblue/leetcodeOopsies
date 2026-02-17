/*
 * Problem: 145. Binary Tree Postorder Traversal
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/1921657178/
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
        traversal(cur->right, res);
        res.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};
