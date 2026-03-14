/*
 * Problem: 383. Ransom Note
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/ransom-note/submissions/1947549238/
 * Language: cpp
 * Date: 2026-03-14
 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mag[26] = {0};
        for (auto& c : magazine) {
            mag[c - 'a']++;
        }
        for (auto& c : ransomNote) {
            mag[c - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (mag[i] < 0) {
                return false;
            }
        }
        return true;
    }
};
