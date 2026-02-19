/*
 * Problem: 617. Merge Two Binary Trees
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/merge-two-binary-trees/submissions/1923978077/
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return nullptr;
        int rootVal;
        if (root1 == nullptr) return root2;
        else if (root2 == nullptr) return root1;
        else rootVal = root1->val + root2->val;
        TreeNode* node = new TreeNode(rootVal);
        node->left = mergeTrees(root1->left, root2->left);
        node->right = mergeTrees(root1->right, root2->right);
        return node;
    }
};
