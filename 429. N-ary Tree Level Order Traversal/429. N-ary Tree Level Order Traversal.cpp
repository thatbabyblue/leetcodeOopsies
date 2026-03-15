/*
 * Problem: 429. N-ary Tree Level Order Traversal
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
 * Language: cpp
 * Date: 2026-03-15
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);
                for (Node* child : node->children) {
                    que.push(child);
                }
            }
            res.push_back(vec);
        } 
        return res;
    }
};
