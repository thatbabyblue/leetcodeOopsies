/*
 * Problem: 242. Valid Anagram
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/valid-anagram/submissions/1947545298/
 * Language: cpp
 * Date: 2026-03-14
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (auto& c : s) {
            record[c - 'a']++;
        }
        for (auto& c : t) {
            record[c - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) return false;
        }
        return true;
    }
};
