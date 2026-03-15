/*
 * Problem: 151. Reverse Words in a String
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/reverse-words-in-a-string/submissions/1948726385/
 * Language: cpp
 * Date: 2026-03-15
 */

class Solution {
public:
    void removeExtraspaces(string& s) {
        int slow = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (slow > 0) s[slow++] = ' ';
                while (i < s.size() && s[i] != ' ') {
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    string reverseWords(string s) {
        removeExtraspaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (s[i] == ' ' || i == s.size()) {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};
