/*
 * Problem: 108. Convert Sorted Array to Binary Search Tree
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
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
    TreeNode* getTree(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = getTree(nums, left, mid - 1);
        node->right = getTree(nums, mid + 1, right);
        return node;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return getTree(nums, 0, nums.size() - 1);
    }
};
