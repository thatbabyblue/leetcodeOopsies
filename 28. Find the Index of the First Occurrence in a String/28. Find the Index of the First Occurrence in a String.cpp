/*
 * Problem: 28. Find the Index of the First Occurrence in a String
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 * Language: cpp
 * Date: 2026-02-16
 */

class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[j] != s[i]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) j++;
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        vector<int> next(needle.size(), 0);
        getNext(&next[0], needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) j++;
            if (j == needle.size()) return i - needle.size() + 1;
        }
        return -1;
    }
};
