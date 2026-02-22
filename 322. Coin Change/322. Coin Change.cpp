/*
 * Problem: 322. Coin Change
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/coin-change/submissions/1926804841/
 * Language: cpp
 * Date: 2026-02-22
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int bagSize = amount;
        vector<int> dp(bagSize + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= bagSize; j++) {
                if (j >= coins[i] && dp[j - coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if (dp[bagSize] == INT_MAX) return -1;
        return dp[bagSize];
    }
};
