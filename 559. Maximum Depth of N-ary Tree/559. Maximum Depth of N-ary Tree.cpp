/*
 * Problem: 559. Maximum Depth of N-ary Tree
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/submissions/1922835026/
 * Language: cpp
 * Date: 2026-02-18
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
        int max = INT_MIN;
        for (int i = 0; i < node->children.size(); i++) {
            int curD = getDepth(node->children[i]);
            if (curD > max) max = curD;
        }
        return max == INT_MIN ? 1 : 1 + max;
    }
    int maxDepth(Node* root) {
        return getDepth(root);
    }
};
