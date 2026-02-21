/*
 * Problem: 494. Target Sum
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/target-sum/submissions/1925890559/
 * Language: cpp
 * Date: 2026-02-21
 */

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int a : nums) sum += a;
        if (abs(target) > sum) return 0;
        if ((target + sum) % 2) return 0;
        int bagSize = (target + sum) / 2;
        vector<int> dp(1001, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};
