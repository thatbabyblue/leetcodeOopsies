/*
 * Problem: 459. Repeated Substring Pattern
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/repeated-substring-pattern/
 * Language: cpp
 * Date: 2026-02-16
 */

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end() - 1);
        if (t.find(s) != std::string::npos) return true;
        return false;
    }
};
