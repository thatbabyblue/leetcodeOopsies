/*
 * Problem: 501. Find Mode in Binary Search Tree
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/find-mode-in-binary-search-tree/submissions/1924047861/
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
    int maxCnt = 0;
    int cnt = 0;
    vector<int> res;
    TreeNode* pre = nullptr;
    void traversal(TreeNode* cur) {
        if (cur == nullptr) return;
        traversal(cur->left);
        if (pre == nullptr) cnt = 1;
        else if (pre->val == cur->val) cnt++;
        else cnt = 1;
        pre = cur;
        if (maxCnt == cnt) {
            res.push_back(cur->val);
        }
        if (cnt > maxCnt) {
            res.clear();
            maxCnt = cnt;
            res.push_back(cur->val);
        }
        traversal(cur->right);
    }
    vector<int> findMode(TreeNode* root) {
        maxCnt = 0;
        cnt = 0;
        res.clear();
        pre = nullptr;
        traversal(root);
        return res;
    }
};
