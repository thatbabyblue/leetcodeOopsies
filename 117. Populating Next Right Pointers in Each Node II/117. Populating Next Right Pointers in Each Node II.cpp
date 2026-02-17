/*
 * Problem: 117. Populating Next Right Pointers in Each Node II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/submissions/1922636744/
 * Language: cpp
 * Date: 2026-02-17
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            Node* pre = que.front();
            que.pop();
            if (pre->left) que.push(pre->left);
            if (pre->right) que.push(pre->right);
            for (int i = 1; i < size; i++) {
                Node* cur = que.front();
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
                pre->next = cur;
                pre = cur;
            }
        }
        return root;
    }
};
