/*
 * Problem: 455. Assign Cookies
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/assign-cookies/submissions/1925794641/
 * Language: cpp
 * Date: 2026-02-20
 */

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (index < g.size() && s[i] >= g[index]) {
                index++;
            }
        }
        return index;
    }
};
