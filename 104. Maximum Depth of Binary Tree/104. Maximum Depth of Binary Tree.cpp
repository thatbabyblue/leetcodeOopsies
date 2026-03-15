/*
 * Problem: 104. Maximum Depth of Binary Tree
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/1949531600/
 * Language: cpp
 * Date: 2026-03-15
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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int res = 0;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            res++;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return res;
    }
};
