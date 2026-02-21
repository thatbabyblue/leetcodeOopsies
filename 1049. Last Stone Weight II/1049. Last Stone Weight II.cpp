/*
 * Problem: 1049. Last Stone Weight II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/last-stone-weight-ii/submissions/1925883176/
 * Language: cpp
 * Date: 2026-02-21
 */

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(15001, 0);
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }
        int target = sum / 2;
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};
