/*
 * Problem: 474. Ones and Zeroes
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/ones-and-zeroes/submissions/1925903322/
 * Language: cpp
 * Date: 2026-02-21
 */

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs) {
            int zeroSum = 0;
            int oneSum = 0;
            for (char c : str) {
                if (c == '0') zeroSum++;
                else oneSum++;
            }
            for (int i = m; i >= zeroSum; i--) {
                for (int j = n; j >= oneSum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroSum][j - oneSum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
