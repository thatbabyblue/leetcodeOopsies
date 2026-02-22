/*
 * Problem: 143. Reorder List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/reorder-list/submissions/1926828943/
 * Language: cpp
 * Date: 2026-02-22
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* cur = head;
        vector<ListNode*> vec;
        while (cur) {
            vec.push_back(cur);
            cur = cur->next;
        }
        cur = head;
        int i = 1;
        int j = vec.size() - 1;
        int cnt = 0;
        while (i <= j) {
            if (cnt % 2) {
                cur->next = vec[i];
                i++;
            } else {
                cur->next = vec[j];
                j--;
            }
            cur = cur->next;
            cnt++;
        }
        cur->next = nullptr;
    }
};
