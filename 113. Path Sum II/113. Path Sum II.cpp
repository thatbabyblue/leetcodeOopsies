/*
 * Problem: 113. Path Sum II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/path-sum-ii/submissions/1923763568/
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
    void traversal(TreeNode* node, int cnt, vector<vector<int>>& res, vector<int>& path) {
        if (!node->left && !node->right && cnt == 0) {
            res.push_back(path);
            return;
        }
        if (!node->left && !node->right) return;
        if (node->left) {
            path.push_back(node->left->val);
            cnt -= node->left->val;
            traversal(node->left, cnt, res, path);
            cnt += node->left->val;
            path.pop_back();
        }
        if (node->right) {
            path.push_back(node->right->val);
            cnt -= node->right->val;
            traversal(node->right, cnt, res, path);
            cnt += node->right->val;
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        res.clear();
        path.clear();
        if (root == nullptr) return res;
        path.push_back(root->val);
        traversal(root, targetSum - root->val, res, path);
        return res;
    }
};
