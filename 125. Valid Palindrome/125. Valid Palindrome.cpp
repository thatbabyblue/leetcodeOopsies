/*
 * Problem: 125. Valid Palindrome
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/valid-palindrome/submissions/1950642230/
 * Language: cpp
 * Date: 2026-03-17
 */

class Solution {
public:
    void convert(string& s) {
        int slow = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] = tolower(s[i]);
        }
        for (int fast = 0; fast < s.size(); fast++) {
            if ((s[fast] >= 'a' && s[fast] <= 'z') || (s[fast] >= '0' && s[fast] <= '9')) s[slow++] = s[fast];
        }
        s.resize(slow);
    }
    bool isPalindrome(string s) {
        convert(s);
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};
