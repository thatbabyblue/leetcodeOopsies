/*
 * Problem: 279. Perfect Squares
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/perfect-squares/submissions/1926808693/
 * Language: cpp
 * Date: 2026-02-22
 */

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++) {
                dp[j] = min(dp[j - i * i] + 1, dp[j]);
            }
        }
        return dp[n];
    }
};
