/*
 * Problem: 392. Is Subsequence
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/is-subsequence/submissions/1927817056/
 * Language: cpp
 * Date: 2026-02-22
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size()) return false;
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        if (dp[s.size()][t.size()] == s.size()) return true;
        return false;
    }
};
