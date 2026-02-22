/*
 * Problem: 300. Longest Increasing Subsequence
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/longest-increasing-subsequence/submissions/1927753440/
 * Language: cpp
 * Date: 2026-02-22
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > res) res = dp[i];
        }
        return res;
    }
};
