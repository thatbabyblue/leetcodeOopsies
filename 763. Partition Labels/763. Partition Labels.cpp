/*
 * Problem: 763. Partition Labels
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/partition-labels/submissions/1931500390/
 * Language: cpp
 * Date: 2026-02-26
 */

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] = i;
        }
        vector<int> res;
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, hash[s[i] - 'a']);
            if (i == right) {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};
