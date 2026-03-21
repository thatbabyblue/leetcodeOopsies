/*
 * Problem: 424. Longest Repeating Character Replacement
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/longest-repeating-character-replacement/submissions/1955165162/
 * Language: cpp
 * Date: 2026-03-21
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {};
        int left = 0;
        int max_freq = 0;
        int res = 0;
        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;
            max_freq = max(max_freq, count[s[right] - 'A']);
            if (right - left + 1 - max_freq > k) {
                count[s[left] - 'A']--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
