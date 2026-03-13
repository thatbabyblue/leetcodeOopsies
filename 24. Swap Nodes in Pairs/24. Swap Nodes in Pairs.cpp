/*
 * Problem: 24. Swap Nodes in Pairs
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/swap-nodes-in-pairs/submissions/1946644872/
 * Language: cpp
 * Date: 2026-03-13
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* temp = cur->next;
            ListNode* temp1 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = temp;
            cur->next->next->next = temp1;
            cur = cur->next->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
