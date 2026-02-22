/*
 * Problem: 129. Sum Root to Leaf Numbers
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/1927847304/
 * Language: cpp
 * Date: 2026-02-22
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
    int res;
    vector<int> path;
    int vecToInt(const vector<int>& vec) {
        int sum = 0;
        for (int i = 0; i < vec.size(); i++) {
            sum = 10 * sum + vec[i];
        }
        return sum;
    }
    void traversal(TreeNode* cur) {
        if (cur->left == nullptr && cur->right == nullptr) {
            res += vecToInt(path);
            return;
        }
        if (cur->left) {
            path.push_back(cur->left->val);
            traversal(cur->left);
            path.pop_back();
        }
        if (cur->right) {
            path.push_back(cur->right->val);
            traversal(cur->right);
            path.pop_back();
        }
    }
    int sumNumbers(TreeNode* root) {
        res = 0;
        path.clear();
        path.push_back(root->val);
        traversal(root);
        return res;
    }
};
