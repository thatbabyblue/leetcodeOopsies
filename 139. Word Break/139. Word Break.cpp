/*
 * Problem: 139. Word Break
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/word-break/submissions/1926813249/
 * Language: cpp
 * Date: 2026-02-22
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int bagSize = s.size();
        vector<int> dp(bagSize + 1, false);
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for (int j = 1; j <= bagSize; j++) {
            for (int i = 0; i < j; i++) {
                string word = s.substr(i, j - i);
                if (dp[i] && uset.find(word) != uset.end()) dp[j] = true;
            }
        }
        return dp[bagSize];
    }
};
