/*
 * Problem: 844. Backspace String Compare
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/backspace-string-compare/submissions/1942290576/
 * Language: cpp
 * Date: 2026-03-08
 */

class Solution {
public:
    int backSpace(string& s) {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            if (s[fast] == '#') {
                if (slow > 0) slow--;
            } else s[slow++] = s[fast];
        }
        return slow;
    }
    bool backspaceCompare(string s, string t) {
        int sizeS = backSpace(s);
        int sizeT = backSpace(t);
        if (sizeS != sizeT) return false;
        for (int i = 0; i < sizeS; i++) {
            if (s[i] != t[i]) return false;
        }
        return true;
    }
};
