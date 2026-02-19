/*
 * Problem: 106. Construct Binary Tree from Inorder and Postorder Traversal
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/1923868842/
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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder, int inorderBegin, int inorderEnd, int postorderBegin, int postorderEnd) {
        if (postorderBegin == postorderEnd) return nullptr;
        int rootVal = postorder[postorderEnd - 1];
        TreeNode* root = new TreeNode(rootVal);
        if (postorderEnd - postorderBegin == 1) return root;

        int breakpt;
        for (breakpt = inorderBegin; breakpt < inorderEnd; breakpt++) {
            if (inorder[breakpt] == rootVal) break;
        }

        int leftinorderBegin = inorderBegin;
        int leftinorderEnd = breakpt;
        int rightinorderBegin = breakpt + 1;
        int rightinorderEnd = inorderEnd;

        int leftpostorderBegin = postorderBegin;
        int leftpostorderEnd = postorderBegin + breakpt - inorderBegin;
        int rightpostorderBegin = postorderBegin + breakpt - inorderBegin;
        int rightpostorderEnd = postorderEnd - 1;

        root->left = traversal(inorder, postorder, leftinorderBegin, leftinorderEnd, leftpostorderBegin, leftpostorderEnd);
        root->right = traversal(inorder, postorder, rightinorderBegin, rightinorderEnd, rightpostorderBegin, rightpostorderEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};
