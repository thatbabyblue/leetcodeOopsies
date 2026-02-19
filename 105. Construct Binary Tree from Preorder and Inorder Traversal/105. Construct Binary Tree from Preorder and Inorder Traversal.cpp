/*
 * Problem: 105. Construct Binary Tree from Preorder and Inorder Traversal
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/1923876394/
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
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder, int inorderBegin, int inorderEnd, int preorderBegin, int preorderEnd) {
        if (preorderBegin == preorderEnd) return nullptr;
        int rootVal = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootVal);
        if (preorderEnd - preorderBegin == 1) return root;

        int breakpt;
        for (breakpt = inorderBegin; breakpt < inorderEnd; breakpt++) {
            if (inorder[breakpt] == rootVal) break;
        }

        int leftinorderBegin = inorderBegin;
        int leftinorderEnd = breakpt;
        int rightinorderBegin = breakpt + 1;
        int rightinorderEnd = inorderEnd;

        int leftpreorderBegin = preorderBegin + 1;
        int leftpreorderEnd = preorderBegin + breakpt - inorderBegin + 1;
        int rightpreorderBegin = preorderBegin + breakpt - inorderBegin + 1;
        int rightpreorderEnd = preorderEnd;

        root->left = traversal(preorder, inorder, leftinorderBegin, leftinorderEnd, leftpreorderBegin, leftpreorderEnd);
        root->right = traversal(preorder, inorder, rightinorderBegin, rightinorderEnd, rightpreorderBegin, rightpreorderEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0 || preorder.size() == 0) return nullptr;
        return traversal(preorder, inorder, 0, inorder.size(), 0, preorder.size());
    }
};
