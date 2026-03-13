/*
 * Problem: 160. Intersection of Two Linked Lists
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/1946692470/
 * Language: cpp
 * Date: 2026-03-13
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
        int sizeA = 0;
        int sizeB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while (curA) {
            sizeA++;
            curA = curA->next;
        }
        while (curB) {
            sizeB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if (sizeB > sizeA) {
            swap(curA, curB);
            swap(sizeA, sizeB);
        }
        int gap = sizeA - sizeB;
        while (gap--) {
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
