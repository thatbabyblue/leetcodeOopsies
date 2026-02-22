/*
 * Problem: 674. Longest Continuous Increasing Subsequence
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/longest-continuous-increasing-subsequence/submissions/1927767099/
 * Language: cpp
 * Date: 2026-02-22
 */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
            if (dp[i] > res) res = dp[i];
        }
        return res;
    }
};
