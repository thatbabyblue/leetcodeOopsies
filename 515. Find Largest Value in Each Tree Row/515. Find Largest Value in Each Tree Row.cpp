/*
 * Problem: 515. Find Largest Value in Each Tree Row
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/submissions/1922617618/
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int max = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->val > max) max = node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(max);
        }
        return res;
    }   
};
