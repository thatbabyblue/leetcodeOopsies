/*
 * Problem: 416. Partition Equal Subset Sum
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/partition-equal-subset-sum/submissions/1925868893/
 * Language: cpp
 * Date: 2026-02-21
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2) return false;
        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(10001, 0));
        
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= target; j++) {
            if (j >= nums[0]) dp[0][j] = nums[0];
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                if (j < nums[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
            }
        }
        if (dp[nums.size() - 1][target] == target) return true;
        return false;
    }
};
