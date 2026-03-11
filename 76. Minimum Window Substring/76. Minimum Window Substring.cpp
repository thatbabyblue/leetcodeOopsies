/*
 * Problem: 76. Minimum Window Substring
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/minimum-window-substring/submissions/1944587521/
 * Language: cpp
 * Date: 2026-03-11
 */

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        unordered_map<char, int> mapT;
        for (auto& c : t) {
            mapT[c]++;
        }
        int left = 0;
        int resLen = INT_MAX;
        int resStart = 0;
        int have = 0;
        int tCnt = mapT.size();
        unordered_map<char, int> mapS;
        for (int right = 0; right < s.size(); right++) {
            if (mapT.count(s[right])) {
                mapS[s[right]]++;
                if (mapS[s[right]] == mapT[s[right]]) {
                    have++;
                }

                while (have == tCnt) {
                    if (right - left + 1 < resLen) {
                        resLen = right - left + 1;
                        resStart = left;
                    }
                    if (mapT.count(s[left])) {
                        mapS[s[left]]--;
                        if (mapS[s[left]] < mapT[s[left]]) have--;
                    }
                    left++;
                }
            }
        }
        if (resLen == INT_MAX) return "";
        return s.substr(resStart, resLen);
    }
};
