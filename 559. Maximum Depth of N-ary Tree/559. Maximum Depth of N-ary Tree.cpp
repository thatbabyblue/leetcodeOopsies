/*
 * Problem: 559. Maximum Depth of N-ary Tree
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/submissions/1952637815/
 * Language: cpp
 * Date: 2026-03-19
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int getDepth(Node* node) {
        if (node == NULL) return 0;
        int depth = 0;
        for (int i = 0; i < node->children.size(); i++) {
            depth = max(depth, getDepth(node->children[i]));
        }
        depth = 1 + depth;
        return depth;
    }
    int maxDepth(Node* root) {
        return getDepth(root);
    }
};
