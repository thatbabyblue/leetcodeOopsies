/*
 * Problem: 49. Group Anagrams
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/group-anagrams/
 * Language: cpp
 * Date: 2026-03-17
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        for (string& str : strs) {
            string count(26, 0);
            for (auto c : str) count[c - 'a']++;
            map[count].push_back(str);
        }
        for (auto& pair : map) {
            res.push_back(pair.second);
        }
        return res;
    }
};
