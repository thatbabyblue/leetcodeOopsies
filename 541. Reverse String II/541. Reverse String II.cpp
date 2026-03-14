/*
 * Problem: 541. Reverse String II
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/reverse-string-ii/submissions/1948432448/
 * Language: cpp
 * Date: 2026-03-14
 */

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            if (i + k < s.size()) {
                reverse(s.begin(), s.begin() + i + k);
            }else {
                reverse(s.begin(), s.end());
            }
        }
        return s;
    }
};
