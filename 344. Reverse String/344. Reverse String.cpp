/*
 * Problem: 344. Reverse String
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/reverse-string/submissions/1948427017/
 * Language: cpp
 * Date: 2026-03-14
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};
