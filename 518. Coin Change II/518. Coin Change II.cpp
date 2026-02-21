/*
 * Problem: 518. Coin Change II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/coin-change-ii/submissions/1926777082/
 * Language: cpp
 * Date: 2026-02-21
 */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int bagSize = amount;
        vector<vector<uint64_t>> dp(coins.size(), vector<uint64_t>(bagSize + 1, 0));
        for (int j = 0; j <= bagSize; j++) {
            if (j % coins[0] == 0) dp[0][j] = 1;
        }
        for (int i = 0; i < coins.size(); i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < coins.size(); i++) {
            for (int j = 1; j <= bagSize; j++) {
                if (coins[i] > j) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
            }
        }
        return dp[coins.size() - 1][bagSize];
    }
};
