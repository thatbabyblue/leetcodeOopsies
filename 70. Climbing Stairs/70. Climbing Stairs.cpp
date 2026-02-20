/*
 * Problem: 70. Climbing Stairs
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/climbing-stairs/submissions/1925807661/
 * Language: cpp
 * Date: 2026-02-20
 */

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
