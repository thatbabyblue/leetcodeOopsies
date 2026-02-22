/*
 * Problem: 1035. Uncrossed Lines
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/uncrossed-lines/submissions/1927797673/
 * Language: cpp
 * Date: 2026-02-22
 */

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int res = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};
