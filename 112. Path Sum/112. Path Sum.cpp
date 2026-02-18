/*
 * Problem: 112. Path Sum
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/path-sum/submissions/1923757479/
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
    bool traversal(TreeNode* node, int count) {
        if (!node->left && !node->right && count == 0) return true;
        if (!node->left && !node->right) return false;
        if (node->left) {
            count -= node->left->val;
            if (traversal(node->left, count)) return true;
            count += node->left->val;
        }
        if (node->right) {
            count -= node->right->val;
            if (traversal(node->right, count)) return true;
            count += node->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return traversal(root, targetSum - root->val);
    }
};
