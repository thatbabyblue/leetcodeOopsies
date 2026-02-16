/*
 * Problem: 541. Reverse String II
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/reverse-string-ii/submissions/1921360487/
 * Language: cpp
 * Date: 2026-02-16
 */

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
