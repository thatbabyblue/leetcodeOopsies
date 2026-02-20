/*
 * Problem: 746. Min Cost Climbing Stairs
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/min-cost-climbing-stairs/description/
 * Language: cpp
 * Date: 2026-02-20
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];
    }
};
