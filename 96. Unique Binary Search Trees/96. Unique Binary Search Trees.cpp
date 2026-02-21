/*
 * Problem: 96. Unique Binary Search Trees
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/unique-binary-search-trees/submissions/1925853663/
 * Language: cpp
 * Date: 2026-02-21
 */

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
