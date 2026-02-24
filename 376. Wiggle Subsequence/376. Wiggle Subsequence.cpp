/*
 * Problem: 376. Wiggle Subsequence
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/wiggle-subsequence/submissions/1929193704/
 * Language: cpp
 * Date: 2026-02-24
 */

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        dp[0][0] = dp[0][1] = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[i][0] = dp[i][1] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};
