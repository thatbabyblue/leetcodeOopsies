/*
 * Problem: 654. Maximum Binary Tree
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/maximum-binary-tree/submissions/1923891775/
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
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left >= right) return nullptr;
        int maxIndex = left;
        for (int i = left + 1; i < right; i++) {
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }

        TreeNode* node = new TreeNode(nums[maxIndex]);
        node->left = traversal(nums, left, maxIndex);
        node->right = traversal(nums, maxIndex + 1, right);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};
