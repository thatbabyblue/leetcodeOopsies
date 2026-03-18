/*
 * Problem: 3. Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/1951716641/
 * Language: cpp
 * Date: 2026-03-18
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = INT_MIN;
        if (s.size() == 0) return 0;
        unordered_set<char> set; 
        int left = 0, right = 0;
        while (right < s.size()) {
            if (set.find(s[right]) == set.end()) {
                set.insert(s[right]);
            } else {
                while (s[left] != s[right]) {
                    set.erase(s[left]);
                    left++;
                }
                left++;
            }
            cout << left << right << endl;
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
