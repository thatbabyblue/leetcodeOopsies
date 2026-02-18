/*
 * Problem: 404. Sum of Left Leaves
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/sum-of-left-leaves/submissions/1922988463/
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftSum = sumOfLeftLeaves(root->left);
        if (root->left && !root->left->left && !root->left->right) {
            leftSum = root->left->val; 
        }
        int rightSum = sumOfLeftLeaves(root->right);
        return leftSum + rightSum;
    }
};
