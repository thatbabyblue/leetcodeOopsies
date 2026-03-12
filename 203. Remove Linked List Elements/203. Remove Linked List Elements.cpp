/*
 * Problem: 203. Remove Linked List Elements
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/remove-linked-list-elements/submissions/1945610803/
 * Language: cpp
 * Date: 2026-03-12
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur;
        cur = dummy;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            } else cur = cur->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
