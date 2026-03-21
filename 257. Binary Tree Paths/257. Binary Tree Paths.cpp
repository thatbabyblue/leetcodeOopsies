/*
 * Problem: 257. Binary Tree Paths
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/binary-tree-paths/submissions/1955067741/
 * Language: cpp
 * Date: 2026-03-21
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
    void traversal(TreeNode* cur, vector<string>& res, vector<int>& path) {
        path.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr) {
            string s;
            for (int i = 0; i < path.size() - 1; i++) {
                s += to_string(path[i]);
                s += "->";
            }
            s += to_string(path[path.size() - 1]);
            res.push_back(s);
            return;
        }
        if (cur->left) {
            traversal(cur->left, res, path);
            path.pop_back();
        }
        if (cur->right) {
            traversal(cur->right, res, path);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        traversal(root, res, path);
        return res;
    }
};
