/*
 * Problem: 160. Intersection of Two Linked Lists
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/1926838041/
 * Language: cpp
 * Date: 2026-02-22
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0;
        int lenB = 0;
        while (curA) {
            curA = curA->next;
            lenA++;
        }
        while (curB) {
            curB = curB->next;
            lenB++;
        }
        curA = headA;
        curB = headB;
        if (lenB >= lenA) {
            swap(curA, curB);
            swap(lenA, lenB);
        }
        int gap = lenA - lenB;
        while(gap--) {
            curA = curA->next;
        }
        while (curA) {
            if (curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};
