/*
 * Problem: 49. Group Anagrams
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/group-anagrams/submissions/1947561236/
 * Language: cpp
 * Date: 2026-03-14
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;
        for (auto& str : strs) {
            string count(26, 0);
            for (auto& c : str) {
                count[c - 'a']++;
            }
            umap[count].push_back(str);
        }
        for (auto& pair : umap) {
            res.push_back(pair.second);
        }
        return res;
    }
};
