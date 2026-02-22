/*
 * Problem: 234. Palindrome Linked List
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/palindrome-linked-list/description/
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
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        ListNode* cur = head;
        while (cur != nullptr) {
            vec.push_back(cur->val);
            cur = cur->next;
        }
        for (int i = 0, j = vec.size() - 1; i < j; i++, j--) {
            if (vec[i] != vec[j]) return false;
        }
        return true;
    }
};
