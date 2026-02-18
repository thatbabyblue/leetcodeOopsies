/*
 * Problem: 257. Binary Tree Paths
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/binary-tree-paths/submissions/1922970645/
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
    void traversal(TreeNode* node, vector<int>& path, vector<string>& res) {
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            string spath;
            for (int i = 0; i < path.size() - 1; i++) {
                spath += to_string(path[i]);
                spath += "->";
            }
            spath += to_string(path[path.size() - 1]);
            res.push_back(spath);
            return;
        }

        if (node->left) {
            traversal(node->left, path, res);
            path.pop_back();
        }
        if (node->right) {
            traversal(node->right, path, res);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if (root == nullptr) return res;
        traversal(root, path, res);
        return res;
    }
};
