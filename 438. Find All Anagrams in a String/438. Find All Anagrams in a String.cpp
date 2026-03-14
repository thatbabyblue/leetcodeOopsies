/*
 * Problem: 438. Find All Anagrams in a String
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/1947592994/
 * Language: cpp
 * Date: 2026-03-14
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size()) return res;
        vector<int> count(26, 0);
        for (auto& c : p) {
            count[c - 'a']++;
        }
        int left = 0, right = 0;
        int needed = p.size();
        while (right < s.size()) {
            if (count[s[right] - 'a'] > 0) needed--;
            count[s[right] - 'a']--;
            if (needed == 0) res.push_back(left);
            if (right - left + 1 == p.size()) {
                if (count[s[left] - 'a'] >= 0) needed++;
                count[s[left] - 'a']++;
                left++;
            }
            right++;
        }
        return res;
    }
};
